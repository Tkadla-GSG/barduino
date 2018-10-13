#include <Arduino.h>

#include <time.h>
#include <Hash.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>

#include "SerialCommand.h"
#include <ArduinoJson.h>

#define WIFI_SSID           "Ragnarok"
#define WIFI_PASSWORD       "maninyWIFIPassw0rd"
#define SERVER_PORT         80
#define WEBSOCKET_PORT      81

#define STATUS_BREWING            "brewing"
#define STATUS_IDLE               "idle"

bool isBrewing = false;

// HTTP Server http://local_ip:80
ESP8266WebServer server(SERVER_PORT);
// Websocket Server ws://local_ip:81
WebSocketsServer webSocketServer(WEBSOCKET_PORT);

SerialCommand sCmd;

const char MAIN_page[] PROGMEM = R"=====(
<!doctype html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <title>Barduino</title>
    </head>
    <body>
        <div id="root"></div>
        <script>
            window.config = {
                websocketEndpoint: "ws:\/\/_ip_",
                assetsEndpoint: "https:\/\/tkadla-gsg.github.io\/barduino\/app\/build\/dist",
            };
        </script>
        <script type="text/javascript" src="https:\/\/tkadla-gsg.github.io\/barduino\/app\/build\/dist\/main.js?v=_version_"></script>
    </body>
</html>
)=====";

void handleRoot() {
  String page = MAIN_page;
  String ip = WiFi.localIP().toString() + ":" + WEBSOCKET_PORT;
  
  // cache bust
  page.replace("_version_", String(random(999999999)));
  page.replace("_ip_", ip);
  
  server.send(200, "text/html", page);
}

void broadcastStatus() {
  String json;
  DynamicJsonBuffer jsonBuffer;
  JsonObject& action = jsonBuffer.createObject();
  JsonObject& payload = action.createNestedObject("payload");
  
  action["type"] = "SERVER_STATUS";
  payload["brewing"] = isBrewing;
  
  action.printTo(json);
  webSocketServer.broadcastTXT(json);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t len) {
  switch (type) {
    case WStype_DISCONNECTED:
      break;
    
    case WStype_CONNECTED:
      broadcastStatus();
      break;

    case WStype_TEXT:
      char * str = (char *)payload;
      memmove(str, str+1, len-2); // string quates form commnad
      str[len-2] = 0;
      Serial.println(str);
      break;
  }
}

void notifyBrewing() {
  isBrewing = true;
  broadcastStatus();
}

void notifyIdle() {
  isBrewing = false;
  broadcastStatus();
}

void unrecognizedCommand(const char *command) {
  Serial.println("command no recognized");
  Serial.println(command);
}

void setup() {
  // setup hardware
  Serial.begin(115200);
  randomSeed(analogRead(0));

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  server.on("/", handleRoot);
  server.begin();

  webSocketServer.begin();                          
  webSocketServer.onEvent(webSocketEvent);   

  sCmd.addCommand(STATUS_BREWING, notifyBrewing);
  sCmd.addCommand(STATUS_IDLE, notifyIdle);

  sCmd.setDefaultHandler(unrecognizedCommand);
}

void loop() {
  sCmd.readSerial();
  server.handleClient();
  webSocketServer.loop();
}
