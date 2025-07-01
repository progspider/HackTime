#include <TM1637Display.h>
#include <virtuabotixRTC.h>

// Пины для TM1637
#define CLK 3   // Пин для CLK (часового импульса)
#define DIO 4   // Пин для DIO (данные)

// Пины для DS1302
#define RST 6   // Пин для RST (сброс)
#define DAT 7   // Пин для DAT (данные)
#define CLK_DS1302 8 // Пин для CLK (часового импульса)

TM1637Display display(CLK, DIO);
virtuabotixRTC myRTC(CLK_DS1302, DAT, RST);

void setup() {
    Serial.begin(9600);
    display.setBrightness(7); // Устанавливаем яркость дисплея
}

void loop() {
    // Получаем текущее время с DS1302
    myRTC.updateTime();
    
    int hour = myRTC.hours;
    int minute = myRTC.minutes;
    
    // Выводим время на TM1637
    display.showNumberDecEx(hour * 100 + minute, 0b01000000, true); // Добавляем двоеточие
    
    // Вывод в Serial Monitor
    Serial.print("Time: ");
    Serial.print(hour);
    Serial.print(":");
    Serial.println(minute);
    
    delay(1000); // Обновляем каждую секунду
}