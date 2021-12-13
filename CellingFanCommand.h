#pragma once

#include "Command.h"
#include "CellingFan.h"

void setUndo(shared_ptr<CellingFan> cellingFan, int prevSpeed) {
	switch (prevSpeed)
	{
	case CellingFan::HIGH:
		cellingFan->hight();
		break;
	case CellingFan::MEDIUM:
		cellingFan->medium();
		break;
	case CellingFan::LOW:
		cellingFan->low();
		break;
	case CellingFan::OFF:
		cellingFan->off();
		break;
	}
}

	class CellingFanHightCommand : public Command {
		shared_ptr<CellingFan> cellingFan;
		int prevSpeed;
	public:
		CellingFanHightCommand(shared_ptr<CellingFan> cellingFan) { this->cellingFan = cellingFan; }//
		void execute() override {
			prevSpeed = cellingFan->getSpeed();
			cellingFan->hight();
		}
		void undo() {
			setUndo(cellingFan, prevSpeed);
		}
	};

	class CellingFanMediumCommand :public Command {
		shared_ptr<CellingFan> cellingFan;
		int prevSpeed;
	public:
		CellingFanMediumCommand(shared_ptr<CellingFan> cellingFan)
		{
			this->cellingFan = cellingFan;
		}////

		void execute() override {
			prevSpeed = cellingFan->getSpeed();
			cellingFan->medium();
		}
		void undo() {
			setUndo(cellingFan, prevSpeed);
		}
	};

	class CellingFanOffCommand :public Command {
		shared_ptr<CellingFan> cellingFan;
		int prevSpeed;
	public:
		CellingFanOffCommand(shared_ptr<CellingFan> cellingFan)
		{
			this->cellingFan = cellingFan;
		}////
		void execute() override {
			prevSpeed = cellingFan->getSpeed();
			cellingFan->off();
		}
		void undo() {
			setUndo(cellingFan, prevSpeed);
		}
	};

