#include "MIDIUSB.h"

#define PINS 4, 2, 3
#define N_PINS 3

const uint8_t pins[] = {PINS};
uint8_t pinStates[N_PINS];

// the setup routine runs once when you press reset:
void setup() {
	for(int i = 0; i < N_PINS; ++i){
		pinMode(pins[i], INPUT);
		pinStates[i] = 0;
	}
}

// the loop routine runs over and over again forever:
void loop() {
	for(int i = 0; i < N_PINS; ++i){
		uint8_t tmpPinState = digitalRead(pins[i]);

		if(tmpPinState && !pinStates[i]){
			midiEventPacket_t noteOn = {0x09, 0x90 | 0, i, 127};
			MidiUSB.sendMIDI(noteOn);

		}else if(!tmpPinState && pinStates[i]){
			midiEventPacket_t noteOff = {0x08, 0x80 | 0, i, 0};
			MidiUSB.sendMIDI(noteOff);
		}

		pinStates[i] = tmpPinState;
	}

	MidiUSB.flush();
}
