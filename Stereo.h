#pragma once
#include <iostream>

using namespace std;

static enum class StereoState{CD,DVD,RADIO};

class Stereo {
	int volume = 0;
	StereoState state = StereoState::RADIO;
public:
	void on() { cout << "Stereo on" << endl;}
	void off() { cout << "Stereo off" << endl;}

	void setCD() {
		cout << "CD setted" << endl;
		state = StereoState::CD;
	}
	void setDVD() {
		cout << "DVD setted" << endl;
		state = StereoState::DVD;
	}
	void setRadio() {
		cout << "RadioSetted" << endl;
		state = StereoState::RADIO;
	}
	void setVolume(int volume)
	{
		this->volume = volume;
		cout << "setted volume:" << volume << endl;
	}

	int getVolume() {return volume;}
	StereoState getState() { return state; }
};