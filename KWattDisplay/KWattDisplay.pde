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

import processing.serial.*;
String inString = "0.0";
String tmpString;
Serial myPort;  // The serial port
float rpm = 0.0;
float rps = 0.0;
float watts = 0.0;
float angVel = 0.0;
int textX = 20;

void setup() {
  size(700,400);
  
  myPort = new Serial(this, "/dev/ttyUSB0", 9600);
  myPort.bufferUntil('\n');
}

void serialEvent(Serial p){
  //Whatever happened to readLine()????
  inString = trim(p.readString());
}

void draw() {


  //Stupid Java cant figure out that 0.0 is a float.
  try{rps = float(inString);}
  catch(NullPointerException a){}
  finally{}

  //Do some Math!!!
  
  //Angular velocity = revolutions per second * 2 pi.
  angVel = rps * 2 * 3.14159;

  //Revolutions per minute = revolutions per second * 60
  rpm = rps * 60;

  //Watts = Angular velocity * Torque
  watts = angVel * 0.81;


  //Spit out the results.
  background(255);
  fill(0);
  textSize(32);
  text("You are achieving ", textX, height/2 - 120);
  textSize(38);
  text(String.format("%.2f RPM", rpm), textX + 300,height/2 - 114);
  textSize(32);
  text("(Revolutions Per Minute)", textX, height/2 - 80);
  text("You are generating about", textX, height/2 - 40);
  textSize(38);
  text(String.format("%.2f Watts of Energy", watts), textX, height/2 + 20);
  textSize(32);
  text("This is based on the idea that an average", textX, height/2 + 80);
  text("of 0.81 N×m is being applied tangentially", textX, height/2 + 120);
  text("to the wheel.", textX, height/2 + 160);
}
