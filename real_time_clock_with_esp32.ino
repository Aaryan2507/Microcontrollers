#include <WiFi.h>
#include <time.h>
#include <TM1637Display.h>

#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO);

// Replace with your WiFi credentials
const char* ssid = "AndroidAP";
const char* password = "hotspassw";

// India Standard Time (UTC +5:30)
const long gmtOffset_sec = 19800;  // 5.5 * 3600. This calibres time to IST from STD
const int daylightOffset_sec = 0;//Daylight Savings?

void setup() {
  Serial.begin(115200);
  display.setBrightness(5);  // 0-7 (adjust for your room)
  
  // Connect to WiFi
  WiFi.begin(ssid, password);//Starts Wi-Fi connection attempt
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {//loops untill wifi connected
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  
  // Configure NTP
  configTime(gmtOffset_sec, daylightOffset_sec, 
             "pool.ntp.org", "time.nist.gov");
  
  // Wait for accurate time
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println("NTP time synced!");
}

void loop() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    display.showNumberDec(1212, false);  // Error: 1212
    delay(1000);
    return;
  }
  
  // Format as HHMM (e.g. 1530 for 3:30 PM)
  int clockTime = (timeinfo.tm_hour * 10 + timeinfo.tm_min / 10) * 10 + 
                  (timeinfo.tm_min % 10);
  
  // Blinking colon effect
  uint8_t colon = (millis() / 500) % 2 ? 0b01000000 : 0;
  display.showNumberDecEx(clockTime, colon, true);
  
  delay(100);  // Smooth update
}
