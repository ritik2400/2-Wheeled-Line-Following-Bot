//This is just test path functions, for testing purposes.
void test()
{
  if(junctions(0))
  {
    digitalWrite(LED_BUILTIN,HIGH);    
    turns(tst[(j-1)]);
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    linefollow();
  }
}
