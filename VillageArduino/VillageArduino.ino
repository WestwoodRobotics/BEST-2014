/*
 * Copyright (c) 2014 Westwood Robotics <code.westwoodrobotics@gmail.com>.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 */
 
//A timer for our Interrupt
volatile long timer = 0;

//A volatile variable for our Interrupt to edit
volatile int hallCount = 0;

//The Revolitons per second counted during the last Interrupt cycle
volatile double hallAvg = 0.0;

//The last read value
volatile int lastReadVal = 0;

//The current read value (Also the last, unless inside the interrupt)
int hallVal = 0;

//A counting variable
int i;

//Pins for the House Lights Relay
int ledPins[8] = {10,11,12,13,A0,A1,A2,A3};

//Array for the House Lights States
int ledStates[8];

//Begin ARDUINO setup
void setup(){

  //Set our Hall pin to input
  pinMode(9, INPUT);

  //Set our relay pins to output
  for(i = 0; i < 8; i++){
    pinMode(ledPins[i], OUTPUT);
  }

  //Stop interrupts
  cli();

  //set timer1 interrupt at 1kHz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;
  // set timer count for 4khz increments
  OCR1A = 499;// = (1/4000)/((1/(16x10^6))x8) - 1
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 bit for 8 prescaler
  TCCR1B |= (1 << CS11);   
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  //Allow interrupts
  sei();

  //Begin Serial communications.
  Serial.begin(9600);
}

//Interrupt
ISR(TIMER1_COMPA_vect) {
  hallVal = digitalRead(9);
  //If our hall value has switched.
  if(hallVal != lastReadVal){
    //Increase the cycle count.
    hallCount += 1;
    //Set the last read to the current read for next read. You read?
    lastReadVal = hallVal;
  }
  //We have done one tick. Count that towards our limit.
  timer += 1;

  //If we hit our limit, reset the timer, and do some math.
  if(timer >= 2000){
    timer = 0;
    //Hall average rotations per second
    //The wheel switches from North to South 36 times in one rotation
    //count divided by 36 = rotations for 1/2 second
    //Revolutions per second = rphs * 2
    hallAvg = (hallCount / 36.0) * 2;
    //Reset the cycle count.
    hallCount = 0;
  }
}

void loop(){
  Serial.print(String(hallAvg) + "\n");
  //These are RPS values, Revolutions per Second.

  //P1
  ledStates[0] = hallAvg >= 2;
  //P2
  ledStates[1] = hallAvg >= 4;
  //P3
  ledStates[2] = hallAvg >= 5;
  //M1
  ledStates[3] = hallAvg >= 6;
  //M3
  ledStates[4] = hallAvg >= 8;
  //C1
  ledStates[5] = hallAvg >= 10;
  //C2
  ledStates[6] = hallAvg >= 12;
  //RP1
  ledStates[7] = hallAvg >= 15;

  //Write the house light states to the relay.
  for(i = 0; i < 8; i++){
    digitalWrite(ledPins[i], ledStates[i]);
  }

  //Wait 1/2 second before doing stuff again (besides timer)
  delay(500);
}
