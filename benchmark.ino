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
	int integerAdditionSubtractionSpeed = testIntegerAdditionSubtraction();
	dot(1);
	int floatingPointMultiplicationSpeed = testFloatingPointMultiplication();
	dot(1);
	int floatingPointDivisionSpeed = testFloatingPointDivision();
	dot(1);
	int integerMultiplicationSpeed = testIntegerMultiplication();
	dot(1);
	int integerDivisionSpeed = testIntegerDivision();
	dot(1);
	int floatingPointAdditionSubtractionSpeed = testFloatingPointAdditionSubtraction();
	dot(1);
	Serial.println(" ");
	Serial.print("You scored a ");
	Serial.print(eepromReadSpeed);
	Serial.println(" on the EEPROM read test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(eepromWriteSpeed);
	Serial.println(" on the EEPROM write test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(integerAdditionSubtractionSpeed);
	Serial.println(" on the integer addition subtraction test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(integerMultiplicationSpeed);
	Serial.println(" on the integer multiplication test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(integerDivisionSpeed);
	Serial.println(" on the integer division test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(floatingPointAdditionSubtractionSpeed);
	Serial.println(" on the floating point addition subtraction test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(floatingPointMultiplicationSpeed);
	Serial.println(" on the floating point multiplication test (lower is better).");
	Serial.print("You scored a ");
	Serial.print(floatingPointDivisionSpeed);
	Serial.println(" on the floating point division test (lower is better).");
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

int testIntegerAdditionSubtraction(){
	int volatile val;
	int i;
	int k;
	int startVal = millis();
	for(int j = 0; j < 10; j++){
		for(i = 0; i < 10000; i++){
			val = i + 42;

		}
		for(k = 0; k < 10000; k++){
			val = k - 42;
		}
		val = 0;
	}
	int endVal = millis();
	return endVal-startVal;
}

int testIntegerMultiplication(){
	int volatile val;
	int i;
	int k;
	int startVal = millis();
	for(int j = 0; j < 10; j++){
		for(i = 0; i < 10000; i++){
			val = i *42;
		}
		for(k = 0; k < 10000; k++){
			val = k * 42;
		}
		val = 0;
	}
	int endVal = millis();
	return endVal-startVal;
}

int testIntegerDivision(){
	int volatile val;
	int i;
	int k;
	int startVal = millis();
	for(int j = 0; j < 10; j++){
		for(i = 0; i < 10000; i++){
			val = i  / 42;
		}
		for(k = 0; k < 10000; k++){
			val = k / 42;
		}
		val = 0;
	}
	int endVal = millis();
	return endVal-startVal;
}

int testFloatingPointAdditionSubtraction(){
	float volatile val = 42.4242;
	int j;
	int i;
	int startVal = millis();
	for(j = 0; j < 10; j++){
		for(i = 0; i < 10000; i++){
			val=val+i;
			val=42.4242;
		}
		for(int k = 0; k < 10000; k++){
			val=val-k;
			val=42.4242;
		}
	}
	int endVal = millis();
	return endVal-startVal;
}

int testFloatingPointMultiplication(){
	float volatile val = 42.4242;
	int j;
	int i;
	int startVal = millis();
	for(j = 0; j < 10; j++){
		for(i = 0; i < 10000; i++){
			val=val*i;
			val=val*i;
			val=42.4242;
		}
	}
	int endVal = millis();
	return endVal-startVal;
}

int testFloatingPointDivision(){
	float volatile val = 42.4242;
	int j;
	int i;
	int startVal = millis();
	for(j = 0; j < 10; j++){
		for(i = 0; i < 10000; i++){
			val=i/val;
			val=i/val;
			val=42.4242;
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

