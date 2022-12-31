#include <Arduino.h>
#include <Servo.h>
#include <IRremote.h>

#define IR_RECV_PIN 4

Servo main_servo;

void setup() {
    main_servo.attach(9);
    
    Serial.begin(9600);
    IrReceiver.begin(IR_RECV_PIN); 
}

int current_pos = 0;

void loop() {
    current_pos = main_servo.read();

    if (IrReceiver.decode()) {
        Serial.println("Received IR transmission!");
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
        IrReceiver.resume();
    }
}