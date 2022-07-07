Bangle.loadWidgets();
Bangle.drawWidgets();

var allData = require("Storage").open(event+".csv", "a");

//Menu Items
var menuItems = {
  "":{"title":"  -- Menu --"},
  '< Back': ()=>{load();},
  /*
  'RECORD': {
      value: !!allData.isRecording,
      onchange: v => {
        allData.isRecording = v;
        writeData();
      }
    },*/
  "Collect Data": function(){writeData(1);},
  "Stop Data": function(){writeData(0);},
};


var menu = E.showMenu(menuItems); //Displaying Menu


Bangle.setCompassPower(1);
var c = Bangle.getCompass();
var a = Bangle.getAccel();
event = "TESTconnectAllData";


function writeData(a){
  var perviousTime = 0;
  var curretTime = Date.now();
  if(a>0){
  while(currentTime>previousTime){
    allData.write(Date.now() + "," + a.x+ "," + a.y+ "," +a.z+"," + c.x +"," + c.y +"," + c.z +"," + c.dx +"," + c.dy +"," + c.dz +"\n");
    previousTime = currentTime;
    currentTime = Date.now();
  }}
  else{
  }
}
