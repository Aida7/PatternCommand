#pragma once
#include <iostream>
using namespace std;

class CellingFan {
	int speed = 0;
public:
	static enum {
		HIGH = 3,
		MEDIUM=2,
		LOW=1,
		OFF=0
	};

	void hight() {
		speed = HIGH;
		cout << "Celling fan speed" << speed << endl;
	}

	void medium() {
		speed = MEDIUM;
		cout << "Celling fan speed" << speed << endl;
	}

	void low() {
		speed = LOW;
		cout << "Celling fan speed" << speed << endl;
	}
	void off() {
		speed = OFF;
		cout << "Celling fan off" << speed << endl;
	}
	const int getSpeed() { return speed;}
};