var five = require("johnny-five");
var board = new five.Board();

var motorRightPin = 9;
var motorLeftPin = 12;

var sensorRightmost = 1;
var sensorRight =2;
var sensorMiddle=3;
var sensorLeft=4;
var sensorLeftmost = 5;

var zeroVoltage =0;
var lowVoltage = 100;
var highVoltage = 255;


board.on("ready", function(){

    this.pinMode(motorRightPin,five.Pin.PWM);
    this.pinMode(motorLeftPin,five.Pin.PWM);

    this.pinMode(sensorRightmost,five.Pin.INPUT);
    this.pinMode(sensorRight,five.Pin.INPUT);
    this.pinMode(sensorMiddle,five.Pin.INPUT);
    this.pinMode(sensorLeft,five.Pin.INPUT);
    this.pinMode(sensorLeftmost,five.Pin.INPUT);

    board.loop(100,followTheLine);
});

function followTheLine(){
    five.Pin.read(sensorRightmost, function(rightMostValue){
        five.Pin.read(sensorRight,function(rightValue){
            five.Pin.read(sensorMiddle,function(middleValue){
                five.Pin.read(sensorLeft, function(leftValue){
                    five.Pin.read(sensorLeftmost,function(leftMostValue){

                        var rightVoltage = zeroVoltage;
                        var leftVoltage = zeroVoltage;
                        //initial state
                        if(rightMostValue && leftMostValue &&
                            rightValue==false && middleValue == false && leftValue==false){
                            rightVoltage = highVoltage;
                            leftVoltage = highVoltage;
                        }
                        //halt stage
                        else if(rightMostValue && leftMostValue &&
                            rightValue && middleValue && leftValue){
                            rightVoltage = zeroVoltage;
                            leftVoltage = zeroVoltage;
                        }

                        // SOS: no line identified
                        else if(!rightMostValue && !leftMostValue &&
                            !rightValue && !middleValue && !leftValue){
                            rightVoltage = zeroVoltage;
                            leftVoltage = zeroVoltage;
                        }
                    });
                });
            });
        });
    });
}