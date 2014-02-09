int PWM_out_pin_motor_right = 9;
int PWM_out_pin_motor_left = 9;
int sensor_leftmost = 5;
int sensor_left = 1;
int sensor_middle = 2;
int sensor_right = 3;
int sensor_rightmost = 4;

int highVoltage = 255;
int lowVoltage = 100;
int zeroVoltage = 0;

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

void loop() {
    int leftVoltage = 0;
    int rightVoltage = 0;
  
    int rightMost = digitalRead(sensor_rightmost);
    int right = digitalRead(sensor_right);
    int middle = digitalRead(sensor_middle);  
    int left = digitalRead(sensor_left);  
    int leftMost = digitalRead(leftMost);
    
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
