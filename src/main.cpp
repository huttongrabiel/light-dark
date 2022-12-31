#include <Arduino.h>
#include <Servo.h>

Servo main_servo;

void setup() {
    main_servo.attach(9);
}

int current_pos = 0;

void loop() {
    current_pos = main_servo.read();

    if (current_pos <= 90) {
        // Sweep Right
        for (current_pos = 0; current_pos <= 180; current_pos++) {
            main_servo.write(current_pos);
            delay(15);
        }
    } else {
        // Sweep Left
        for (current_pos = 180; current_pos >= 0; current_pos--) {
            main_servo.write(current_pos);
            delay(15);
        }
    }
}