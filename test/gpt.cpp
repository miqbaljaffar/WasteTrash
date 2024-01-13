#include <Arduino.h>


// Definisikan pin sensor dan servo
int sensorLogamPin = 2; // Pin sensor logam
int sensorOrganikPlastikPin = 3; // Pin sensor organik dan plastik
int servoLogamPin = 9; // Pin servo untuk sampah logam
int servoOrganikPlastikPin = 10; // Pin servo untuk sampah organik dan plastik

// Setup fungsi
void setup() {
  pinMode(sensorLogamPin, INPUT);
  pinMode(sensorOrganikPlastikPin, INPUT);
  pinMode(servoLogamPin, OUTPUT);
  pinMode(servoOrganikPlastikPin, OUTPUT);
}

// Loop utama
void loop() {
  // Baca nilai sensor logam
  int sensorLogamValue = digitalRead(sensorLogamPin);

  // Cek jika terdeteksi sampah logam
  if (sensorLogamValue == HIGH) {
    rotateServo(servoLogamPin, 90); // Putar servo ke kanan 90°
    delay(2000); // Tunggu 2 detik
    rotateServo(servoLogamPin, 0); // Putar servo kembali ke posisi awal
  }

  // Baca nilai sensor organik dan plastik
  int sensorOrganikPlastikValue = digitalRead(sensorOrganikPlastikPin);

  // Cek jenis sampah yang terdeteksi
  if (sensorOrganikPlastikValue == HIGH) {
    rotateServo(servoOrganikPlastikPin, 90); // Putar servo ke kanan 90° untuk sampah plastik
    delay(2000); // Tunggu 2 detik
    rotateServo(servoOrganikPlastikPin, 0); // Putar servo kembali ke posisi awal
  } else {
    rotateServo(servoOrganikPlastikPin, -90); // Putar servo ke kiri 90° untuk sampah organik
    delay(2000); // Tunggu 2 detik
    rotateServo(servoOrganikPlastikPin, 0); // Putar servo kembali ke posisi awal
  }
}

// Fungsi untuk memutar servo
void rotateServo(int pin, int degree) {
  for (int i = 0; i < 180; i++) {
    if (degree > 0) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(1500 + (degree * 11));
      digitalWrite(pin, LOW);
      delay(20 - (degree * 0.1));
    } else {
      digitalWrite(pin, HIGH);
      delayMicroseconds(500 + (degree * 11));
      digitalWrite(pin, LOW);
      delay(20 + (degree * -0.1));
    }
  }
}
