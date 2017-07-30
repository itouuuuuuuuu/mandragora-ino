// Wi-Fi接続されていればtrueを返す関数
bool isWifiConnect() {
  return WiFi.status() == WL_CONNECTED;
}

