#include <Arduino.h>

#include <time.h>
#include <Hash.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>

#include <ArduinoJson.h>

#include <../constants.h>

#define WIFI_SSID           "Ragnarok"
#define WIFI_PASSWORD       "maninyWIFIPassw0rd"
#define SERVER_PORT         80
#define WEBSOCKET_PORT      81

// HTTP Server http://local_ip:80
ESP8266WebServer server(SERVER_PORT);
// Websocket Server ws://local_ip:81
WebSocketsServer webSocketServer(WEBSOCKET_PORT);

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
  payload["queueLength"] = 0;
  payload["brewing"] = "false";
  
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
      const size_t bufferSize = JSON_OBJECT_SIZE(1) + 40;
      
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(payload);
      const char* command = root["command"];
      const char* id = root["id"];

      Serial.printf(COMMAND_TEMPLATE, command, id);
      break;
  }
}

void setup() {
  // setup hardware
  Serial.begin(115200);
  randomSeed(analogRead(0));

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  server.on("/", handleRoot);
  server.begin();

  webSocketServer.begin();                          
  webSocketServer.onEvent(webSocketEvent);          
}

void loop() {
  server.handleClient();
  webSocketServer.loop();
}
