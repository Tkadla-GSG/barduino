#include <Arduino.h>

#include <time.h>
#include <Hash.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include <WebSocketsClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID           "Ragnarok"
#define WIFI_PASSWORD       "maninyWIFIPassw0rd"
#define SERVER_PORT         80

WebSocketsClient webSocket;

// WebServer local_ip:80
ESP8266WebServer server(SERVER_PORT);

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
  // cache bust
  page.replace("_version_", String(random(999999999)));
  page.replace("_ip_", WiFi.localIP().toString());
  server.send(200, "text/html", page);
}

/*
void sendMessage(String message) {
  Serial.println(message);
  
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["type"] = "message";
  root["id"] = nextCmdId++;
  root["text"] = message;
  root["channel"] = DEV_CHANNEL_ID;
  String json;
  root.printTo(json);
  webSocket.sendTXT(json);
}
*/

void setup() {
  // setup hardware
  Serial.begin(115200);
  randomSeed(analogRead(0));
  Serial.println();

  Serial.printf("Connecting to %s\n", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);     //Connect to your WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  
  Serial.println("Starting server");
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
  webSocket.loop();
}

void webSocketEvent(WStype_t type, uint8_t *payload, size_t len) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[WebSocket] Disconnected\n");
      break;
    
    case WStype_CONNECTED:
      Serial.printf("[WebSocket] Connected to: %s\n", payload);
      break;

    case WStype_TEXT:
      Serial.printf("[WebSocket] Message: %s\n", payload);
      break;
  }
}
