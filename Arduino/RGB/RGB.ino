int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // 7 colors
  showColor(255, 0, 0);   // Red
  delay(1000);

  showColor(0, 255, 0);   // Green
  delay(1000);

  showColor(0, 0, 255);   // Blue
  delay(1000);

  showColor(255, 255, 0); // Yellow (Red + Green)
  delay(1000);

  showColor(0, 255, 255); // Cyan (Green + Blue)
  delay(1000);

  showColor(255, 0, 255); // Magenta (Red + Blue)
  delay(1000);

  showColor(255, 255, 255); // White (Red + Green + Blue)
  delay(1000);
}

void showColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
