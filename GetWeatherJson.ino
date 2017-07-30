// 天気情報をjson形式でサーバーから取得する関数
JsonObject& GetWeatherJson(const char* weatherUrl) {
  
  // wifiに接続できている場合
  if (WiFi.status() == WL_CONNECTED) {

    StaticJsonBuffer<200> jsonBuffer;  // JSON用の固定バッファを確保
    
    HTTPClient http;
 
    http.begin(weatherUrl);         // リクエスト先を指定
    int httpCode = http.GET();  // GETリクエストを送信

    // サーバーからレスポンスがある場合
    if (httpCode > 0) { 
 
      String jsonString = http.getString();                      // レスポンスをString型で取得
      
      char jsonCharAry[jsonString.length()];                     // レスポンスをchar[]型へ変換後に格納する変数
      jsonString.toCharArray(jsonCharAry, jsonString.length());  // レスポンスをchar[]型へ変換

      JsonObject& json = jsonBuffer.parseObject(jsonString);     // JSONBufferに変換し格納
      
      // 変換が失敗したら終了
      if (!json.success()) {
        Serial.println("jsonの変換に失敗しました! ><;");
      }

      return json;
      
    }
    // サーバーからレスポンスがない場合
    else {
      Serial.println("サーバーからのレスポンスがありません");
      Serial.println("天気情報を取得できませんでした");
    }
 
    http.end();  // コネクションを終了

    jsonBuffer.clear(); // バッファをクリア

  }
  // wifiに接続できていない場合
  else {
    Serial.println("Wi-Fiに接続されていません");
  }
  
}
