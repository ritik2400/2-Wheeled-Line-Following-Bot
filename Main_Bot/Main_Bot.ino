short int s[8],s_sum,j=0;//sensor readings and their sums. junction count.

//Motor Driver used had PWM and Direction pins for each motor.
short int LP=9,RP=11,LD=6,RD=10;//These are the Pin numbers for PWM and Direction pin of left and right motors
float RMS,LMS,//Calculated motor speed through PD Controller
      turnspd=60,basespd=110;//Initial speeds before PID for forward and turns.

//PID Variables
int firsttime;
float PID, p_err=0, err, Kp=18, Kd=250;//Kp=18.7 Kd=150.......battery=12.27
//15,70

//Delay Variables
#define de 110*5//110*15 
int offd=200;
const int fdd=(de/basespd);//offd=70

//factors are the fractions to take into account the dissimilarities of motor rpms due to unresolvable problems.
#define r_factor 1
#define l_factor 1.05

//Paths to be followed by the Bot
int pth1[]={0,0,-1,1,-1,1,0,-1,0,2};
int pth2A[]={0,1,0,-1,0,1,0,0,-1,0,0,0,-1,2};
int pth2B[]={0,1,0,-1,0,1,-1,-1,0,0,0,1,2};
int pth3A[]={1,0,1,0,-1,0,1,0,0,0,1,2};
int pth3B[]={-1,0,0,0,-1,0,1,0,-1,0,-1,2};
int pth4A[]={1,0,1,-1,0,-1,1,0,-2,0,1,0,-1,2};
int pth4B[]={-1,0,0,0,1,-1,0,1,0,-2,0,1,0,-1,2};
int tst[]={0,-1,2};

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(12,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(RD,OUTPUT);
  pinMode(LD,OUTPUT);
  pinMode(RP,OUTPUT);
  pinMode(LP,OUTPUT);
}

void loop(){
  sensor_read();
  disp_val();
}


void tloop() 
{
  if(!digitalRead(12) && !digitalRead(8) && !digitalRead(5) && !digitalRead(4))
  {
    path1();
  }
  else if(!digitalRead(12) && !digitalRead(8) && !digitalRead(5) && digitalRead(4))
  {
    path2A();
  }
  else if(!digitalRead(12) && !digitalRead(8) && digitalRead(5) && !digitalRead(4))
  {
    path2B();
  }
  else if(!digitalRead(12) && !digitalRead(8) && digitalRead(5) && digitalRead(4))
  {
    path3A();
  }
  else if(!digitalRead(12) && digitalRead(8) && !digitalRead(5) && !digitalRead(4))
  {
    path3B();
  }
  else if(!digitalRead(12) && digitalRead(8) && !digitalRead(5) && digitalRead(4))
  {
    path4A();
  }
  else if(!digitalRead(12) && digitalRead(8) && digitalRead(5) && !digitalRead(4))
  {
    path4B();
  }
  else if(digitalRead(12) && !digitalRead(8) && !digitalRead(5) && !digitalRead(4))
  {
    fwd(100);
  }
  else if(digitalRead(12) && digitalRead(8) && !digitalRead(5) && !digitalRead(4))
  {
    back();
  }
  else
  {
    err_cal();
    if(s_sum>=4)
    {
      halt(100000);
    }
    linefollow();
  }
} 
//void loop()
//{
//    err_cal();
//    if(s_sum>=4)
//    {
//      halt(100000);
//    }
//    linefollow();
//}
