#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "env.h"              // 環境変数読み込み
extern "C" {
  #include "user_interface.h" // system_adc_read()を使用可能にする
}
 
const char* ssid       = envSsid;        // Wi-FiのSSID
const char* password   = envPassword;    // Wi-Fiのパスワード
const char* weatherUrl = envWeatherUrl;  // 天気取得APIのURL

int soilMoisture = 0;   // 土壌湿度センサーで取得した値
  
void setup () {
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (!isWifiConnect()) {
    delay(1000);
    Serial.println("Connecting...");
  }
  
}
 
void loop() {

  // TOUTから出力される湿度を取得
  soilMoisture = system_adc_read();  
  
  delay(1000);          
  Serial.print("SoilMoisture = " );                       
  Serial.println(soilMoisture);
    
  // 土壌湿度をサーバーへ送信
  SendSoilMoisture(soilMoisture);

  // ここに湿度によって動く処理

  // ここに湿度によって話す処理

  // 天気情報をjson形式でサーバーから取得
  JsonObject& json = GetWeatherJson(weatherUrl);

  const char* weather = json["weather"];
  Serial.println(weather);

  // ここに天気によって動く処理

  // ここに天気によって話す処理

  Serial.println();
  delay(1000);
 
}
