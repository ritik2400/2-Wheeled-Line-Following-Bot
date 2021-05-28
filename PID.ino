void sensor_read()//Takes the input from the sensors of LSA08
{
  s[0] = digitalRead(2);
  s[1] = digitalRead(3);
  s[2] = digitalRead(A0);
  s[3] = digitalRead(A5);
  s[4] = digitalRead(A1);
  s[5] = digitalRead(A4);
  s[6] = digitalRead(A2);
  s[7] = digitalRead(A3);
  s_sum = s[0] + s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7];
}

void disp_val()//Displays sensor readings on Serial Monitor.
{
  Serial.print(s[0]);
  Serial.print(s[1]);
  Serial.print(s[2]);
  Serial.print(s[3]);
  Serial.print(s[4]);
  Serial.print(s[5]);
  Serial.print(s[6]);
  Serial.println(s[7]);
//  Serial.println(err);
}

void err_cal()// Calculates the error from the path.
{
  sensor_read();
  err = (s[0] * (-3.5) + s[1] * (-2.5) + s[2] * (-1.5) + s[3] * (-0.5) + s[4] * (0.5) + s[5] * (1.5) + s[6] * (2.5) + s[7] * (3.5)) / s_sum;
//  Serial.println(err);
}

void PID_cal()//PID Corrections required to resolve the error.
{
  PID = Kp * err + ( Kd * (err - p_err)) ;//( (micros() - previous_time));
  p_err = err;
//  previous_time = micros();
}

void motor_speed()//Makes changes in the Motor Speeds, also limits the speeds to max and min values of PWM speeds.
{
  RMS = basespd - PID;
  LMS = basespd + PID;
  if (RMS > 255)
  {
    RMS = 255;
  }
  if (RMS < 0)
  {
    RMS = 0;
  }
  if (LMS > 255)
  {
    LMS = 255;
  }
  if (LMS < 0)
  {
    LMS = 0;
  }
}

void linefollow()//Straight Line following code, which calls PID and motor speed control Functions: PID_cal() and motor_speed()
{
  PID_cal();
  motor_speed();
  analogWrite(RP, RMS * r_factor);
  analogWrite(LP, LMS * l_factor);
  digitalWrite(RD, 0);
  digitalWrite(LD, 0);
}
