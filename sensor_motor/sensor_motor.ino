//sensors are attached to these pins
int sensor_1 = 0;
//int sensor_2 = 1;
//int sensor_3 = 2;
//int sensor_4 = 3;
//int sensor_5 = 4;

//motors are attached to these pins
int motor_1 = 9;
//int motor_2 = 9;
//int motor_1 = 10;
//int motor_2 = 11;

//led for testing
//int led = 9;


void setup(){

//initializing sensor pins as input pins.
pinMode(sensor_1, INPUT);
//pinMode(sensor_2, INPUT);
//pinMode(sensor_3, INPUT);
//pinMode(sensor_4, INPUT);
//pinMode(sensor_5, INPUT);

//initializing sensor pins as input pins.
pinMode(motor_1, OUTPUT);
//pinMode(motor_2, OUTPUT);
//pinMode(motor_3, OUTPUT);
//pinMode(motor_4, OUTPUT);


// initialize the digital pin as an output.
//pinMode(led, OUTPUT);


//setting bod rate for console output
Serial.begin(9600);

}


void loop(){

//raed the digital value from sensor
int val = digitalRead(sensor_1);
//digitalWrite(led, val);
val = val * 255;
analogWrite(motor_1,val);
Serial.println(val);
}
