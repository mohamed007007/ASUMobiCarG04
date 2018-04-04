/*************************************
 * Line Follower Robot* 
 *  Code Written by MYBOTIC  *
 *************************************/

#define SEN_1_PIN A2
#define SEN_2_PIN A3
#define SEN_3_PIN A4
#define SEN_4_PIN A5

#define IN1 10
#define IN2 9
#define IN3 6
#define IN4 5

#define MOT_RIGHT 0
#define MOT_LEFT 1
 

void setup()
{
  pinMode(SEN_1_PIN, INPUT);
  pinMode(SEN_2_PIN, INPUT);
  pinMode(SEN_3_PIN, INPUT);
  pinMode(SEN_4_PIN, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  char cSen_Status = 0b00000000;

  cSen_Status = cRead_Sensor();

  if((cSen_Status == 0b00000110) || (cSen_Status == 0b00000111) || (cSen_Status == 0b00001110)) //Forward
  {
    vMotor_Control(MOT_RIGHT, 80);
    vMotor_Control(MOT_LEFT, 80);
  }
  else if((cSen_Status == 0b00000010) || (cSen_Status == 0b00000011) || (cSen_Status == 0b00000001))
  {
    vMotor_Control(MOT_RIGHT, 0);
    vMotor_Control(MOT_LEFT, 80);
  }
  else if((cSen_Status == 0b00000100) || (cSen_Status == 0b00001100) || (cSen_Status == 0b00001000))
  {
    vMotor_Control(MOT_RIGHT, 80);
    vMotor_Control(MOT_LEFT, 0);
  }
  else 
  {
    vMotor_Control(MOT_RIGHT, 0);
    vMotor_Control(MOT_LEFT, 0);    
  }

  
  Serial.println((short)cSen_Status);
}

char cRead_Sensor(void) //stop
{
  short sSen_Pin[4] = {SEN_1_PIN, SEN_2_PIN, SEN_3_PIN, SEN_4_PIN};
  char cStatus = 0b00000000;

  for(short i=0; i<4; i++)
  {
    cStatus = cStatus | (digitalRead(sSen_Pin[i]) << i);
  }

  return cStatus;
}

void vMotor_Control(short sWhich_Mot, short sSpeed)
{
  if(sWhich_Mot == MOT_RIGHT)
  {
    if(sSpeed < 0) //reverse
    {
      sSpeed = abs(sSpeed);
      analogWrite(IN1, sSpeed);
      digitalWrite(IN2, LOW);
    }
    else
    {
      digitalWrite(IN1, LOW);
      analogWrite(IN2, sSpeed);
    }
  }
  else
  {
    if(sSpeed < 0) //reverse
    {
      sSpeed = abs(sSpeed);
      analogWrite(IN3, sSpeed);
      digitalWrite(IN4, LOW);
    }
    else
    {
      digitalWrite(IN3, LOW);
      analogWrite(IN4, sSpeed);
    }    
  }
}
