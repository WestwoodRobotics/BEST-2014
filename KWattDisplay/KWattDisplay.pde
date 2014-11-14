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
  inString = trim(p.readString());
}

void draw() {  
  try{rps = float(inString);}
  catch(NullPointerException a){}
  finally{}
  
  angVel = rps * 2 * 3.14159;

  rpm = rps * 60;
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
