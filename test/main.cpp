#include <Arduino.h>
#include <Servo.h>

Servo servo_induktif;
Servo servo_ldr;

#define servoinduktif 9
#define servoldr 10
#define sensorPininduktif 2
#define sensorPinir 5
#define sensorPinldr 7

void setup() {
  servo_induktif.attach(servoinduktif);
  servo_ldr.attach(servoldr);
  servo_induktif.write(90);
  servo_ldr.write(90);
  pinMode(sensorPininduktif, INPUT);
  pinMode(sensorPinir, INPUT);
  pinMode(sensorPinldr, INPUT);
}

void loop() {
  // Baca sensor IR
  int nilaiSensorIR = digitalRead(sensorPinir);

  if (nilaiSensorIR == LOW) {
    // Jika ada objek yang terdeteksi oleh sensor IR
    delay(3000); // Delay 3 detik

    // Baca sensor induktif
    if (digitalRead(sensorPininduktif) == HIGH) {
      // Jika ada barang logam terdeteksi oleh sensor induktif
      servo_induktif.write(0);
      delay(3000); // Delay 3 detik
      servo_induktif.write(90);
      return; // Program selesai
    } else {
      // Jika tidak ada barang logam terdeteksi oleh sensor induktif
      servo_induktif.write(180);
      delay(3000); // Delay 3 detik
      servo_induktif.write(90);
      delay(5000); // Delay 5 detik
    }

    // Baca sensor LDR
    if (digitalRead(sensorPinldr) == HIGH) {
      // Jika ada cahaya terdeteksi oleh sensor LDR
      servo_ldr.write(180);
      delay(3000); // Delay 3 detik
      servo_ldr.write(90);
      return; // Program selesai
    } else {
      // Jika tidak ada cahaya terdeteksi oleh sensor LDR
      servo_ldr.write(0);
      delay(3000); // Delay 3 detik
      servo_ldr.write(90);
      return; // Program selesai
    }
  }
  
  // Jika tidak ada objek yang terdeteksi oleh sensor IR
  servo_induktif.write(90);
  servo_ldr.write(90);

  delay(1000);
}
