var five = require("johnny-five");
var board = new five.Board();

var motorOneOutputPin = 9;
var motorTwoOutputPin = 10;

var lowVoltage = 100;
var highVoltage = 255;

var led;

board.on("ready",function(){
	this.pinMode(motorOneOutputPin,five.Pin.PWM);
	this.pinMode(motorTwoOutputPin,five.Pin.PWM);
	led = five.Led({pin: 13});
	board.loop(5000, followTheLine);
});


function followTheLine(){
		this.analogWrite(motorOneOutputPin,highVoltage);
		//this.analogWrite(motorTwoOutputPin,highVoltage);
		led.on();
		board.wait(1000, function(){
			this.analogWrite(motorOneOutputPin,lowVoltage);
			//this.analogWrite(motorTwoOutputPin,highVoltage);
			led.off();
		});
}