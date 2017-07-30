// 土壌湿度をサーバーへ送信する関数
void SendSoilMoisture(int soilMoisture) {

  // wifiに接続できている場合
  if (WiFi.status() == WL_CONNECTED) { 

    HTTPClient http;

    http.begin("サーバーのurl?湿度=" + (String)soilMoisture); // リクエスト先を指定
    int httpCode = http.GET();  // GETリクエストを送信

    // サーバーからレスポンスがある場合
    if (httpCode > 0) { 
 
      String jsonString = http.getString();  // レスポンスをString型で取得
      
      // なんやかんや処理
      
    }
    // サーバーからレスポンスがない場合
    else {
      Serial.println("サーバーからのレスポンスがありません");
      Serial.println("土壌湿度情報を送信できませんでした");
    }

    http.end();  // コネクションを終了
    
  }
  // wifiに接続できていない場合
  else {
    Serial.println("Wi-Fiに接続されていません");
  }
  
}
