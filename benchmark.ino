#include <EEPROM.h>
#include <avr/pgmspace.h>

void setup(){
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  Serial.println("Loading tests...");
}

void loop(){
	Serial.print("Benchmarking...");
	int eepromReadSpeed = testEepromRead();
	dot(1);
	int eepromWriteSpeed = testEepromWrite();
	dot(1);

	Serial.println(" ");
	Serial.print("You scored a ");
	Serial.print(eepromReadSpeed);
	Serial.println(" on the EEPROM read test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(eepromWriteSpeed);
	Serial.println(" on the EEPROM write test (lower is better).");
	while(true){
		delay(1000);
	}

}

int testEepromWrite(){
	for (int i = 0; i < 512; i++){
    	EEPROM.write(i, 0);
    }
	int startVal = millis();
	for(int i = 0; i < 512; i++){
		EEPROM.write(i, 1);
	}
	int endVal = millis();
	return endVal-startVal;
}

int testEepromRead(){
	int val;
	int startVal = millis();
	for(int i = 0; i < 2000; i++){
		for(int i = 0; i < 512; i++){
			val = EEPROM.read(i);
		}
	}
	int endVal = millis();
	return endVal-startVal;
}

void dot(int j){
	for(int i = 0; i < j; i++){
		Serial.print(".");
	}
}
