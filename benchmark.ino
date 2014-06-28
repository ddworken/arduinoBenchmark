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
	int additionSubtractionSpeed = testAddictionSubtraction();
	dot(1);
	int floatingPointMultiplicationSpeed = testFloatingPointMultiplication();
	dot(1);
	Serial.println(" ");
	Serial.print("You scored a ");
	Serial.print(eepromReadSpeed);
	Serial.println(" on the EEPROM read test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(eepromWriteSpeed);
	Serial.println(" on the EEPROM write test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(additionSubtractionSpeed);
	Serial.println(" on the integer addition subtraction test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(floatingPointMultiplicationSpeed);
	Serial.println(" on the floating point multiplication test (lower is better).");
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

int testAddictionSubtraction(){
	int val;
	int startVal = millis();
	for(int i = 0; i < 10000; i++){
		val = i + 42;
	}
	for(int i = 0; i < 10000; i++){
		val = i - 42;
	}
	int newVal = val;
	int endVal = millis();
	return endVal-startVal;
}

int testFloatingPointMultiplication(){
	float val = 42.4242;
	int startVal = millis();
	for(int i = 0; i < 10000; i++){
		val=val*i;
		val=val*i;
		val=42.4242;
		val=val*i;
		val=val*i;
		val=42.4242;
		val=val*i;
		val=val*i;
		val=42.4242;
		val=val*i;
		val=val*i;
		val=42.4242;
		val=val*i;
		val=val*i;
		val=42.4242;
	}
	int endVal = millis();
	return endVal-startVal;
}

int ramSpeedTest(){
	//String longString1 PROGMEM = "This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. This is a long string meant to use up a large amount of ram. ";
}

void dot(int j){
	for(int i = 0; i < j; i++){
		Serial.print(".");
	}
}
