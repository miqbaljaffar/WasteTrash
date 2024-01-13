// Inisialisasi servo dan sensor
#include <Arduino.h>
#include <Servo.h>

Servo myservo;
int sensorPin = 2; // Pin untuk sensor induktif
int sensorValue = 0; // Nilai yang dibaca oleh sensor induktif

void setup() {
  // Memasang servo pada pin 9
  myservo.attach(9);
  // Mengatur pin sensor sebagai input
  pinMode(sensorPin, INPUT);
  // Menginisialisasi komunikasi serial dengan baud rate 9600
  Serial.begin(9600);
  // Mengatur posisi awal servo menjadi 90 derajat (bukan 0 derajat)
  myservo.write(90);
}

void loop() {
  // Baca nilai dari pin digital 13
  bool data = digitalRead(13);

  if (data == HIGH) { // Ubah menjadi HIGH karena digitalRead() mengembalikan nilai HIGH atau LOW
    myservo.write(180); // Ganti servo.write() menjadi myservo.write()
    delay(3000);
    myservo.write(90); // Ganti servo.write() menjadi myservo.write()
  } else { // Jika bukan HIGH (maka LOW atau nilai lainnya)
    myservo.write(0); // Ganti servo.write() menjadi myservo.write()
    delay(3000);
    myservo.write(90); // Ganti servo.write() menjadi myservo.write()
  }

  // Baca nilai dari sensor induktif
  sensorValue = analogRead(sensorPin);

  // Mengirimkan nilai sensor ke port serial
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
}
