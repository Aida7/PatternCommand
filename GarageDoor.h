#pragma once
#include <iostream>

using namespace std;

class GarageDoor {
	void up() { cout << "Garage Door Up" << endl;}
	void down() { cout << "Garage Door Down" << endl; }
	void stop() { cout << "Garage Door Stoped" << endl; }
	void lightOn() { cout << "Garage Light On" << endl; }
	void lightOff() { cout << "Garage Light off" << endl; }
};