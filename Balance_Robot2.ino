#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int valx, valy, valz;
// Your motor pins
int PWMA = 11;
int MA1 = 9;
int MA2 = 10;
int PWMB = 3;
int MB1 = 6;
int MB2 = 5;
int STBY = 8;
//int output,PreError,Error,Integral,Kp,Ki,Kd;
int Error;
int output;
int PreError;
int Integral;
float Kp = 6;
float Ki = 0.0;
float Kd = 0;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(PWMA, OUTPUT);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(STBY, OUTPUT);
  Serial.println("Initialize MPU");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
  MotorStop(1);
}

void loop() {
  gyro();
  CalError();
  PID();
  if (output < 0) {
    output = abs(output);
    Backward(output+1, 1);
  } else if (output > 0) {
    Forward(output+1, 1);
  }
}
