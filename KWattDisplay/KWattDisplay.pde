import processing.serial.*;
String inString = "0.0";
Serial myPort;  // The serial port
Double rpm = 0.0D;
Double watts = 0.0D;
Double angVel = 0.0D;
int textX = 20;

void setup() {
  size(700,400);
  
  myPort = new Serial(this, "/dev/ttyUSB0", 9600);
}

void serialEvent(Serial p){
  inString = p.readStringUntil(10);
}

void draw() {
  try{rpm = Double.parseDouble(inString);}
  catch(NullPointerException a){}
  finally{rpm = 0.0D;}
  rpm /= 36.0;
  angVel = rpm * 4 * Math.PI;

  rpm *= 120.0;
  watts = angVel * 0.81;
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
