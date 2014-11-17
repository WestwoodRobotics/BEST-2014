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

//Import the serial library
import processing.serial.*;

//Set a default string that will be used until the arduino sends up data
String inString = "0.0";

//The serial port
Serial myPort;

//Revolutions per minute
float rpm = 0.0;

//Revolutions per second
float rps = 0.0;

//Wattage calculated
float watts = 0.0;

//Angular Velocity calculated
float angVel = 0.0;

//Tangential force
float tanForce = 0.81;

//Text x position
int textX = 20;

int numSpots = 8;

int spotSize = 50;
int spotXStart = 800;
int spotYStart = 35;
int spotYSpacing = 30;

int spotY[] = new int[numSpots];
int spotLimit[] = {2, 4, 5, 6, 8, 10, 12, 15};
String spotPower[] = new String[numSpots];
String spotName[] = {
  "Low Level Housing Unit 1",
  "Low Level Housing Unit 2",
  "Low Level Housing Unit 3",
  "Mid Level Housing Unit 1",
  "Mid Level Housing Unit 2",
  "Condo Group 1",
  "Condo Group 2",
  "High Level Community Housing"
};

PImage img;

//Setup the app
void setup() {

  //Set the size of the app
  size(1300, 630);

  for(int i = 0; i < numSpots; i++){
    spotY[(numSpots - 1) - i] = spotYStart + (spotYSpacing + spotSize) * i;
    spotPower[i] = String.format("%.2f", spotLimit[i] * 6.28318 * tanForce);
  }
  
  //Open the serial port
  myPort = new Serial(this, "/dev/ttyUSB0", 9600);

  //Set the serial port to buffer each line to this character
  myPort.bufferUntil('\n');

  img = loadImage("logocolor.min.png");
}

//What to do when we get serial data
void serialEvent(Serial p){
  //Whatever happened to readLine()????
  inString = trim(p.readString());
}

//The app's draw method
void draw() {


  //Stupid Java cant figure out that 0.0 is a float.
  try{rps = float(inString);}
  catch(NullPointerException a){}
  finally{}

  //Do some Math!!!
  
  //Angular velocity = revolutions per second * 2 pi.
  angVel = rps * 6.28318;

  //Revolutions per minute = revolutions per second * 60
  rpm = rps * 60;

  //Watts = Angular velocity * Torque
  watts = angVel * tanForce;


  //Spit out the results.
  background(102, 180, 190, 0.1);
  fill(0);
  textSize(32);
  text("You are achieving ", textX, 40);
  textSize(38);
  text(String.format("%.2f RPM", rpm), textX + 300,44);
  textSize(32);
  text("(Revolutions Per Minute)", textX, 80);
  text("You are generating about", textX, 120);
  textSize(42);
  text(String.format("%.2f Watts of Energy", watts), textX, 180);
  textSize(32);
  text("This is based on the idea that an average", textX, 240);
  text("of 0.81 N×m is being applied tangentially", textX, 280);
  text("to the wheel. It is an arbitrary value,", textX, 320);
  text("obtained from the product of mg * r", textX, 360);

  textSize(20);
  fill(0);
  for(int i = 0; i < numSpots; i++){
    text(spotName[i], spotXStart + spotSize + 5, spotY[i] - 10);
    text("Power Output Required: " + spotPower[i] + " Watts", spotXStart + spotSize + 5, spotY[i] + 15);
  }
  
  for(int i = 0; i < numSpots; i++){
    if(rps >= spotLimit[i])
      fill(0, 255, 0);
    else
      fill(255, 0, 0);

    ellipse(spotXStart, spotY[i], spotSize, spotSize);
  }

  image(img, 80, 400);
}
