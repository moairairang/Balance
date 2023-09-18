void CalError() {
  if (valx == 90) {
    Error = 0;
  }
  if (valx <= 80) {
    Error = valx - 90;
  }
  if (valx >= 100) {
    Error = valx - 90;
  }
  //Error = Error/2;
  // Serial.print("Error = ");
  // Serial.println(Error);
}