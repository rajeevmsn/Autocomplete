/*
 Rajeev Mylapalli<rajeev.msn@gmail.com> ,January 2022
 
 This code is to get User ID of the application.

 Refer to BasicHTTPSClient.ino in examples

 Following the instructions from connect git repo

----------
To get UserID
----------
curl --request GET \
  --url $CONNECT_URL/oauth/user \
  --header 'Authorization: Bearer '$access_token

Response:
{ "id": "xxxx" }

-----------
To get access token use this format
https://connect-project.io/authorize?client_id=pub_ZZZZZZZZZZZZZZZ&redirect_uri=zzzzzzzzz


Try to refresh the token and replace it once in a while
*/ 


#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

#define TOKEN "38c732fb6af367ed96998acbdcec02d80a2130c2"
#define HOST "https://connect-project.io"
#define URL  "/oauth/user"

//At MakerLab
#define SSID_NAME "MovuinoTest"
#define SSID_PW "MovuinoTest"

//const uint8_t fingerPrint[20]={0x10, 0xFA, 0x37, 0x06, 0x7A, 0x0D, 0xCC, 0xC8, 0x90, 0x47, 0x2B, 0xEF, 0xE7, 0xE3, 0x49, 0x3F, 0xFA, 0xB4, 0x8E, 0x26};

ESP8266WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.print("Connecting to ");
  Serial.println(SSID_NAME);
  WiFi.begin(SSID_NAME, SSID_PW); //Connecting to WiFi Network

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("."); //We are waiting to connect to WIFI
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

void getID(){
  std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
  client->setInsecure();
  //in case if we want to include SSL certificate
  //client->setFingerprint(fingerprint);
  HTTPClient https;
  
  /*To get UserID
curl --request GET \
  --url $CONNECT_URL/oauth/user \
  --header 'Authorization: Bearer '$access_token

Response:
{ "id": "xxxx" }
*/
  https.begin(*client, "https://connect-project.io"URL);
  https.setAuthorization("");
  https.addHeader("Authorization", "Bearer "TOKEN);
    
   int httpCode = https.GET();

    if (httpCode>0){
      String payload = https.getString();   //Get the request response payload
      Serial.println(payload); 
      https.end();      
    }
    else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
}

void loop() {
  getID();
  delay(5000);
}
