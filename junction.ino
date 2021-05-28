//Function to calculate if there is junction in the path.
int junctions(int f)//f argument is to know if forward is needed to be executed.
{
  err_cal();
  if(s_sum >= 4)
  {
    j++;
    if(j==5 && f==1)
    {
      while(s_sum>=4)
      {
        fwd(50);
        err_cal();
      }
    }
    fwd(fdd);//
    return 1;
  }
  else
  {
    return 0;
  }
}

//Function to execute turns in a path.
void turns(int n)
{
  switch (n)
  {
    //Halt
    case 2:
    halt(100000);
    break;

    //Right
    case 1:
    halt(100);//halt(200);= Good...100=satisfactory
    right();
    delay(offd);
    do
    {
      right();
      sensor_read();
    }while((!s[5])||(!s[6]));
    halt(50);
//    halt(100000);
    break;

    //Forward
    case 0:
    fwd(60);
    break;

    //Left
    case -1:
    halt(100);//halt(200);= Good...100=satisfactory
    left();
    delay(offd);
    do
    {
      left();
      sensor_read();
    }while((!s[2])||(!s[1]));//(good at(!s[2]).....better at (!s[2])||(!s[1])=safe and better)==turnspd(50).............
//closer we get to center sensor greater risk of bot not turning
    halt(50);
//    halt(100000);
    break;

    //Blind Path
    case -2:
    fwd(50);
    do
    {
      err_cal();
    }while(blind());
    break;
  }
}
