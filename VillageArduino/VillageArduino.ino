
long timer = 0;
int hallCount = 0;
int hallAvg = 0;
int lastReadVal = 0;
int hallVal = 0;

int i;

int ledPins[8] = {10,11,12,13,A0,A1,A2,A3};

int ledStates[8];

void setup(){
  pinMode(9, INPUT);

  for(i = 0; i < 8; i++){
    pinMode(ledPins[i], OUTPUT);
  }

  // TIMER SETUP- the timer interrupt allows preceise timed measurements of the reed switch
  //for mor info about configuration of arduino timers see http://arduino.cc/playground/Code/Timer1
  cli();//stop interrupts

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

  sei();//allow interrupts
  //END TIMER SETUP

  Serial.begin(9600);
}


ISR(TIMER1_COMPA_vect) {
  hallVal = digitalRead(9);
  if(hallVal == lastReadVal){
    hallCount += 1;
    lastReadVal = hallVal;
  }
  timer += 1;
  if(timer >= 2000){
    timer = 0;
    hallAvg = hallCount;
    hallCount = 0;
  }
}

void loop(){
  Serial.print(String(hallAvg) + "\n");
  ledStates[0] = hallAvg > 25;
  ledStates[1] = hallAvg > 50;
  ledStates[2] = hallAvg > 75;
  ledStates[3] = hallAvg > 100;
  ledStates[4] = hallAvg > 120;
  ledStates[5] = hallAvg > 135;
  ledStates[6] = hallAvg > 150;
  ledStates[7] = hallAvg > 170;

  for(i = 0; i < 8; i++){
    digitalWrite(ledPins[i], ledStates[i]);
  }
  delay(500);
}