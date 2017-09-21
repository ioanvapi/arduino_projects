#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CEnable, CSelect
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);

  setupRF24();
}

void loop() {
  while (Serial.available()) {
    String msg = Serial.readString(); // read the incoming data as string
    char text[msg.length()];
    msg.toCharArray(text, msg.length());
    radio.write(&text, sizeof(text));
  }
}

void setupRF24() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  const char text[] = "Proba";
  radio.write(&text, sizeof(text));
  delay(1000);
}
