void Forward(int MotorSpeed, int Time) {
  digitalWrite(STBY, HIGH); //disable standby
  digitalWrite(PWMA, HIGH);
  analogWrite(MA1, MotorSpeed);
  analogWrite(MA2, 0);
  digitalWrite(PWMB, HIGH);
  analogWrite(MB1, MotorSpeed);
  analogWrite(MB2, 0);
  delay(Time);
}

void Backward(int MotorSpeed, int Time) {
  digitalWrite(PWMA, HIGH);
  analogWrite(MA1, 0);
  analogWrite(MA2, MotorSpeed);
  digitalWrite(PWMB, HIGH);
  analogWrite(MB1, 0);
  analogWrite(MB2, MotorSpeed);
  delay(Time);
}

void MotorStop(int Time) {
  digitalWrite(STBY, LOW);  //enable standby
  digitalWrite(PWMA, HIGH);
  analogWrite(MA1, 0);
  analogWrite(MA2, 0);
  digitalWrite(PWMB, HIGH);
  analogWrite(MB1, 0);
  analogWrite(MB2, 0);
  delay(Time);
}