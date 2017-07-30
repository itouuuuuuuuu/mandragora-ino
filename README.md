# 2017 開発合宿 Mandragora

## 環境設定
* ArduinoIDE をインストール
* [Arduino] > [Preferences] > [追加のボードマネージャのURL]に下記URLをコピペ
  * http://arduino.esp8266.com/stable/package_esp8266com_index.json (安定版) 
  * http://dl-id.igrr.me/versions/2.3.0/package_esp8266com_index.json  (うまくいかない場合)
* [ツール] > [ボード] > [ボードマネージャ] で [esp8266] をインストール
* [ツール] > [ボード] で [Generic ESP8266 Module]を選択
* [ツール]を以下の様に設定
  * Flash Mode : QIO
  * Flash Frequency : 40MHz
  * Upload Using : Serial
  * CPU Frequency : 80MHz
  * Flash Size : 4M(3M SPIFFS)　(3MBをファイルシステムで使用 / 1MBをスケッチで使用)
  * Debug port : Disabled
  * Debug Level : None
  * Reset Method : nodemcu
  * Upload Speed : 115200
  * シリアルポート : /dev/cu.usbserial-hogehoge
  * 書込装置 : USBasp