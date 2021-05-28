//Functions taking care of directions in which bot needs to turn by giving signals to suitable Arduino Pins. 
//d,h = It is the milliseconds of delay for the bot to move forward for that time.
void fwd(int d)
{
  analogWrite(RP, basespd * r_factor);
  analogWrite(LP, basespd * l_factor);
  digitalWrite(RD, 0);
  digitalWrite(LD, 0);
  delay(d);
}
void back()
{
  analogWrite(RP, basespd * 1);
  analogWrite(LP, basespd * 1);
  digitalWrite(RD, 1);
  digitalWrite(LD, 1);
}
void left()
{
  analogWrite(RP, turnspd);
  analogWrite(LP, turnspd * l_factor);
  digitalWrite(RD, 0);
  digitalWrite(LD, 1);
}
void right()
{
  analogWrite(RP, turnspd * r_factor);
  analogWrite(LP, turnspd);
  digitalWrite(RD, 1);
  digitalWrite(LD, 0);
}
void halt(long int h)
{
  analogWrite(RP, 0);
  analogWrite(LP, 0);
  digitalWrite(RD, 1);
  digitalWrite(LD, 1);
  delay(h);
}
