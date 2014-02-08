var jenkinsapi = require('jenkins-api');

var jenkins = jenkinsapi.init("http://ajagtap:spider!2@buildserver01:8080");

jenkins.last_result('IMS_UI_TestSuite', function(err, data) {
  if (err){ return console.log(err); }
  console.log(data)
});