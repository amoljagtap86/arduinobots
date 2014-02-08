var five = require("johnny-five");

var board = new five.Board();

board.on("ready",function(){
	 led = new five.Led({pin:13});
	led.strobe();
 });