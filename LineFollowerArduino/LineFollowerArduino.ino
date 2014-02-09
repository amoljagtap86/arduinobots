int PWM_out_pin_motor_right = 9;
int PWM_out_pin_motor_left = 9;
int sensor_leftmost = 5;
int sensor_left = 6;
int sensor_middle = 2;
int sensor_right = 3;
int sensor_rightmost = 4;

int highVoltage = 255;
int lowVoltage = 100;
int zeroVoltage = 0;

float Kp=0,Ki=0,Kd=0;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;


void setup() {
  pinMode(PWM_out_pin_motor_right, OUTPUT);
  pinMode(PWM_out_pin_motor_left, OUTPUT);
  
  pinMode(sensor_leftmost, INPUT);
  pinMode(sensor_left, INPUT);
  pinMode(sensor_middle, INPUT);
  pinMode(sensor_right, INPUT);
  pinMode(sensor_rightmost, INPUT);
  
  Serial.begin(9600);
}

void read_sensor_values(){
    int rightMost = digitalRead(sensor_rightmost);
    int right = digitalRead(sensor_right);
    int middle = digitalRead(sensor_middle);  
    int left = digitalRead(sensor_left);  
    int leftMost = digitalRead(sensor_leftmost);
//stop if sensor all white 
    //if(leftMost ==1 && left== 1 && middle ==1 && right== 1 &&  rightMost== 1)
    //{
      //stop motor
    //}


    if(leftMost ==1 && left== 1 && middle ==1 && right== 1 &&  rightMost== 0)
    {
      error = 16;
    }
    
    if(leftMost == 1 && left== 1 && middle ==1 && right== 0 &&  rightMost== 1)
    {
      error = 15;
    }
        if(leftMost == 1 && left== 1 && middle ==1 && right== 0 &&  rightMost== 0)
    {
      error = 14;
    }
        if(leftMost == 1 && left== 1 && middle ==0 && right== 1 &&  rightMost== 1)
    {
      error = 13;
    }
    if(leftMost == 1 && left== 1 && middle ==0 && right== 1 &&  rightMost== 0)
    {
      error = 12;
    }
    if(leftMost == 1 && left== 1 && middle ==0 && right== 0 &&  rightMost== 1)
    {
      error = 11;
    }
    if(leftMost == 1 && left== 1 && middle ==0 && right== 0 &&  rightMost== 0)
    {
      error = 10;
    }
    if(leftMost == 1 && left== 0 && middle ==1 && right== 1 &&  rightMost== 1)
    {
      error = 9;
    }
     if(leftMost == 1 && left== 0 && middle ==1 && right== 1 &&  rightMost== 0)
    {
      error = 8;
    }

     if(leftMost == 1 && left== 0 && middle ==1 && right== 0 &&  rightMost== 1)
    {
      error = 7;
    }

     if(leftMost == 1 && left== 0 && middle ==1 && right== 0 &&  rightMost== 0)
    {
      error = 6;
    }

     if(leftMost == 1 && left== 0 && middle ==0 && right== 1 &&  rightMost== 1)
    {
      error = 5;
    }
    
    if(leftMost == 1 && left== 0 && middle ==0 && right== 1 &&  rightMost== 0)
    {
      error = 4;
    }
    
     if(leftMost == 1 && left== 0 && middle ==0 && right== 0 &&  rightMost== 1)
    {
      error = 3;
    }
    
     if(leftMost == 1 && left== 0 && middle ==0 && right== 0 &&  rightMost== 0)
    {
      error = 2;
    }
    
     if(leftMost == 0 && left== 1 && middle ==1 && right== 1 &&  rightMost== 1)
    {
      error = 1;
    }
    
     if(leftMost == 0 && left== 1 && middle ==1 && right== 1 &&  rightMost== 0)
    {
      error = 0;
    }
    
     if(leftMost == 0 && left== 1 && middle ==1 && right== 0 &&  rightMost== 1)
    {
      error = -1;
    }
    
     if(leftMost == 0 && left== 1 && middle ==1 && right== 0 &&  rightMost== 0)
    {
      error = -2;
    }
    
     if(leftMost == 0 && left== 1 && middle ==0 && right== 1 &&  rightMost== 1)
    {
      error = -3;
    }
    
     if(leftMost == 0 && left== 1 && middle ==0 && right== 1 &&  rightMost== 0)
    {
      error = -4;
    }
    
     if(leftMost == 0 && left== 1 && middle ==0 && right== 0 &&  rightMost== 1)
    {
      error = -5;
    }
    
     if(leftMost == 0 && left== 1 && middle ==0 && right== 0 &&  rightMost== 0)
    {
      error = -6;
    }

     if(leftMost == 0 && left== 0 && middle ==1 && right== 1 &&  rightMost== 1)
    {
      error = -7;
    }
    
     if(leftMost == 0 && left== 0 && middle ==1 && right== 1 &&  rightMost== 0)
    {
      error = -8;
    }
    
     if(leftMost == 0 && left== 0 && middle ==1 && right== 0 &&  rightMost== 1)
    {
      error = -9;
    }
    
     if(leftMost == 0 && left== 0 && middle ==1 && right== 0 &&  rightMost== 0)
    {
      error = -10;
    }

     if(leftMost == 0 && left== 0 && middle ==0 && right== 1 &&  rightMost== 1)
    {
      error = -11;
    }

     if(leftMost == 0 && left== 0 && middle ==0 && right== 1 &&  rightMost== 0)
    {
      error = -12;
    }
    
     if(leftMost == 0 && left== 0 && middle ==0 && right== 0 &&  rightMost== 1)
    {
      error = -13;
    }

     if(leftMost == 0 && left== 0 && middle ==0 && right== 0 &&  rightMost== 0)
    {
      error = -14;
    }
  
}

void loop() {
  
  read_sensor_values();
  
    int leftVoltage = 0;
    int rightVoltage = 0;
  
    
    Serial.print(leftMost);
   Serial.print(left);
    Serial.print(middle);
                 Serial.print(right);
    Serial.println(rightMost);
    
    if(rightMost== 1 && leftMost == 1 &&
       right== 0 && middle == 0 && left == 0)
       {
           
         leftVoltage = highVoltage;
         rightVoltage = highVoltage;
       }
    else if(rightMost==1 && leftMost == 1 &&
       right==1 && middle ==1 && left == 1)
       {
        leftVoltage = zeroVoltage;
        rightVoltage = zeroVoltage;
      }
    else if (rightMost == 0 && leftMost == 0 &&
    right==0 && middle == 0 && left ==0)
    {
        leftVoltage = zeroVoltage;
        rightVoltage = zeroVoltage;
    }
    
   analogWrite( PWM_out_pin_motor_left, leftVoltage);
  analogWrite( PWM_out_pin_motor_right, rightVoltage);
    Serial.println(rightVoltage);
}
