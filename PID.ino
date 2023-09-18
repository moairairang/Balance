void PID()  
{
  output = (Kp * Error) + (Ki * Integral) + Kd * (Error - PreError);   
  
  if(output > 100){
    output=100;
  }
  else if(output < -100){
    output=-100;
  }
  // Serial.print("output =");
  PreError = Error;    
  Integral += Error;
  Serial.println(output);  

}