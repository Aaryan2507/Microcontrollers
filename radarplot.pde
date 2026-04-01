import processing.serial.*;

Serial myPort;
String data = "";
int angle = 0;
int distance = 0;

void setup() {
  size(1000, 600);
  smooth();

  println(Serial.list());   // check port names in console
  myPort = new Serial(this, "COM11", 9600);   // change COM4 to your port
  myPort.bufferUntil('.');
}

void draw() {
  background(0);
  translate(width/2, height - 50);

  drawRadarGrid();
  drawSweepLine();
  drawObject();
  drawLabels();
}

void serialEvent(Serial myPort) {
  data = myPort.readStringUntil('.');
  if (data == null) return;

  data = data.substring(0, data.length()-1); // remove '.'
  int commaIndex = data.indexOf(',');

  if (commaIndex > 0) {
    String a = data.substring(0, commaIndex);
    String d = data.substring(commaIndex + 1);

    angle = int(a);
    distance = int(d);
  }
}

void drawRadarGrid() {
  stroke(0, 255, 0);
  noFill();

  arc(0, 0, 800, 800, PI, TWO_PI);
  arc(0, 0, 600, 600, PI, TWO_PI);
  arc(0, 0, 400, 400, PI, TWO_PI);
  arc(0, 0, 200, 200, PI, TWO_PI);

  line(-400, 0, 400, 0);

  for (int a = 0; a <= 180; a += 30) {
    float x = 400 * cos(radians(a));
    float y = -400 * sin(radians(a));
    line(0, 0, x, y);
  }
}

void drawSweepLine() {
  stroke(0, 255, 0);
  strokeWeight(2);

  float x = 400 * cos(radians(angle));
  float y = -400 * sin(radians(angle));
  line(0, 0, x, y);
}

void drawObject() {
  if (distance > 0 && distance < 40) {
    stroke(255, 0, 0);
    strokeWeight(6);

    float r = map(distance, 0, 40, 0, 400);
    float x = r * cos(radians(angle));
    float y = -r * sin(radians(angle));

    point(x, y);
  }
}

void drawLabels() {
  fill(0, 255, 0);
  textSize(18);
  text("Angle: " + angle + " deg", -470, -500);
  text("Distance: " + distance + " cm", -470, -470);
}
