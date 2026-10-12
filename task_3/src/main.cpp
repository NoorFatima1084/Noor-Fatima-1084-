// Week3-Lecture2
// Timer Interrupt (Internal)
// Embedded IoT System Fall-2026

// Name: TALHA
// Reg#: 1080

#include <Arduino.h>

#define LED 4

hw_timer_t *My_timer = NULL;

// ISR - Interrupt Service Routine
void ARDUINO_ISR_ATTR onTimer()
{
    digitalWrite(LED, !digitalRead(LED));
}

void setup()
{
    pinMode(LED, OUTPUT);

    // Timer frequency = 1 MHz
    // 1 tick = 1 microsecond

    My_timer = timerBegin(1000000);

    // Attach ISR to timer
    timerAttachInterrupt(My_timer, &onTimer);

    // Trigger interrupt every 1,000,000 microseconds
    // = 1 second
    // true = repeat automatically
    // 0 = unlimited reloads

    timerAlarm(My_timer, 1000000, true, 0);
}

void loop()
{
}