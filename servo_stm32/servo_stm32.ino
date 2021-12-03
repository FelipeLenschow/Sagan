
HardwareTimer pwmtimer2(2);
void setup() {
  //pwmtimer4.pause();
  //pwmtimer4.setOverflow(1440000);
  //pwmtimer4.refresh();
  //pwmtimer4.resume();

  pwmtimer2.pause();
  pwmtimer2.setPeriod(20000);
  pwmtimer2.refresh();
  pwmtimer2.resume();


  pinMode(PA0, PWM);
  pinMode(PC13, OUTPUT);
  Serial.begin(9600);

}

void loop() {


  //  digitalWrite(PC13, HIGH);
  //  delayMicroseconds(1000);
  //  digitalWrite(PC13, LOW);
  //  delayMicroseconds(20000 - 1000);

  //  ServoWrite(50);
  //  delay(1000);
  //  ServoWrite(150);
  //  delay(1000);


  for (int i = 0; i < 180; i++) {
    ServoWrite(i, 1);
    Serial.println(i);
    delay(20);
  }
  delay(3000);
  ServoWrite(0, 1);
  delay(3000);

}

void ServoWrite(int Angle, int servo) {
  switch (servo) {
    case 1:
      pwmWrite(PA0, map(constrain(Angle, 0, 180), 0, 180, 1600, 7000));
      break;
    default: break;
  }
}
