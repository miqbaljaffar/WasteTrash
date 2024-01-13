#include <Arduino.h>
#include <Servo.h>

Servo servo_induktif;
Servo servo_ldr;

#define servoinduktif 9
#define servoldr 10
#define sensorPininduktif 2
#define sensorPinir 3

void setup() {
  servo_induktif.attach(servoinduktif);
  servo_ldr.attach(servoldr);
  servo_induktif.write(90);
  servo_ldr.write(90);
  pinMode(sensorPininduktif, INPUT);
  pinMode(sensorPinir, INPUT);
}

void loop() {
  // Baca sensor IR
  int nilaiSensorIR = digitalRead(sensorPinir);

  if (nilaiSensorIR == LOW) {
    // Jika ada objek yang terdeteksi oleh sensor IR
    if (digitalRead(sensorPininduktif) == HIGH) {
      // Lakukan aksi untuk servo sensor induktif
      servo_induktif.write(180);
      delay(1000);
      servo_induktif.write(90);
    } else {
      // Lakukan aksi default untuk servo sensor induktif
      servo_induktif.write(0);
      delay(1000);
      servo_induktif.write(90);
    }
  } else {
    // Jika tidak ada objek yang terdeteksi oleh sensor IR, reset kedua servomotor ke posisi default
    servo_induktif.write(90);
    servo_ldr.write(90);
  }

  delay(1000);
}
