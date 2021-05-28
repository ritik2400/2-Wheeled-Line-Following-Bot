//This Tab contains different paths, with special conditions in each path for their special nodes.
void path1()
{
  if(junctions(0))
  {
    digitalWrite(LED_BUILTIN,HIGH);//Built-In LED at pin 13 stays lit until
    if(j==5)//Junction 5 was a special node in the path, so it was required to have special execution for it.
    {
      while(s_sum>3)
      {
        fwd(0);
        sensor_read();
      }
      while(s_sum<3)
      {
        fwd(0);
        sensor_read();
      }
      fwd(10);
      halt(50);
    }
    else
    {
      turns(pth1[(j-1)]);
    }
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    linefollow();
  }
}
void path2A()
{
  if(junctions(1))
  {
    if(j==5)
    {
     while(s_sum>=4)
     {
        fwd(20);
        err_cal();
     }
    }
    else
    {
      digitalWrite(LED_BUILTIN,HIGH);    
      turns(pth2A[(j-1)]);
      digitalWrite(LED_BUILTIN,LOW);
    }
  }
  else
  {
    if(j==4 || j==5)
    {
      basespd+=0.5;
      Kd+=10;
    }
    else
    {
      basespd=110;
      Kd=250;
    }

    linefollow();
  }
}
void path2B()
{
  if(junctions(1))
  {
    digitalWrite(LED_BUILTIN,HIGH);    
    turns(pth2B[(j-1)]);
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    if(j==4 || j==5)
    {
      basespd+=0.5;
      Kd+=10;
    }
    else
    {
      basespd=110;
      Kd=250;
    }

    linefollow();
  }
}
void path3A()
{
  if(junctions(0))
  {
    digitalWrite(LED_BUILTIN,HIGH);    
    turns(pth3A[(j-1)]);
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    linefollow();
  }
}
void path3B()
{
  if(junctions(0))
  {
    digitalWrite(LED_BUILTIN,HIGH);    
    turns(pth3B[(j-1)]);
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    linefollow();
  }
}
void path4A()
{
  if(junctions(0))
  {
    digitalWrite(LED_BUILTIN,HIGH);    
    turns(pth4A[(j-1)]);
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    if(j>=7 && j<=9)
    {
      basespd+=0.2;
      Kd+=10;
    }
    else
    {
      basespd=110;
      Kd=250;
    }
    if(j==13)
    {
      firsttime=millis();
      while((millis()-firsttime)<=650)
      {
        err_cal();
        linefollow();
      }
      halt(100000);
    }
    linefollow();
  }
}
void path4B()
{
  if(junctions(0))
  {
    digitalWrite(LED_BUILTIN,HIGH);    
    turns(pth4B[(j-1)]);
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    if(j>=8 && j<=10)
    {
      basespd+=0.2;
      Kd+=10;
    }
    else
    {
      basespd=110;
      Kd=250;
    }
    if(j==14)
    {
      firsttime=millis();
      while((millis()-firsttime)<=650)
      {
        err_cal();
        linefollow();
      }
      halt(100000);
    }    
    linefollow();
  }
}
int blind()
{
//  err_cal();
  if(s_sum >= 4)
  {
    digitalWrite(LED_BUILTIN,HIGH);    
    fwd(50);
    do
    {
      err_cal();
      if(s_sum==0)
      {
        fwd(10);
      }
      else
      {
        linefollow();
      }
    }
    while(s_sum < 4);
    fwd(50);
    digitalWrite(LED_BUILTIN,LOW);
    return 0;
  }
  else 
  {
    linefollow();
    return 1;
  }
}
