var jenkinsapi = require('jenkins-api');
var five = require("johnny-five");

var board = new five.Board();
var jenkins = jenkinsapi.init("http://ajagtap:spider!2@buildserver01:8080");

board.on("ready",function(){
	jenkins.last_build_info('IMS_UI_TestSuite', function(err, data) {
		var led = new five.Led({pin:13});
		if (err){ return console.log(err); }
		if(data && data.result==='SUCCESS'){
			led.strobe();
		}
		else{
			led.on();
		}
	});
 }); 	
 