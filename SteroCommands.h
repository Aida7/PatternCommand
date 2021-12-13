#pragma once
#include "Command.h"
#include "Stereo.h"

class StereoOnWithCDCommand : public Command {
	shared_ptr<Stereo> stereo = nullptr;
public:
	StereoOnWithCDCommand(shared_ptr<Stereo> stereo) { this->stereo = stereo; }
	void execute() override {
		stereo->on();
		stereo->setCD();
		stereo->setVolume(11);
	}
	void undo() override {
		stereo->off();
	}
};

	class StereoOnWithRadioCommand : public Command {
		shared_ptr<Stereo> stereo = nullptr;
	public:
		StereoOnWithRadioCommand(shared_ptr<Stereo> stereo) { this->stereo = stereo; }
		void execute() override {
			stereo->on();
			stereo->setRadio();
			stereo->setVolume(15);
		}
		void undo() override {
			stereo->on();
		}
	};

	class StereoOffCommand :public Command {
		shared_ptr<Stereo> stereo = nullptr;
		int prevVolume = 0;
		StereoState prevState = StereoState::RADIO;
	public:
		StereoOffCommand(shared_ptr<Stereo> stereo) { this->stereo = stereo; }
		void execute() override {
			prevVolume = stereo->getVolume();
			prevState = stereo->getState();
			stereo->off();
		}
		void undo() override {
			stereo->on();
			switch (prevState)
			{
			case StereoState::CD:
				stereo->setCD();
				break;
			case StereoState::DVD:
				stereo->setDVD();
				break;
			case StereoState::RADIO:
				stereo->setRadio();
				break;
			}
			stereo->setVolume(prevVolume);
		}
	};
