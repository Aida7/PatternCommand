#include "RemoteControl.h"
#include "Light.h"
#include "Stereo.h"
#include "CellingFan.h"
#include "LightCommands.h"
#include "SteroCommands.h"
#include "CellingFanCommand.h"

int main() {
	unique_ptr<RemoteControl> remote = make_unique<RemoteControl>();

	// Command pattern RECEIEVERS
	shared_ptr<Light> livingRoomLight = make_shared<Light>();
	shared_ptr<Light> bedRoomLight = make_shared<Light>();
	shared_ptr<CellingFan> bedRoomCeilingFan = make_shared<CellingFan>();
	shared_ptr<Stereo> stereo = make_shared<Stereo>();

	//commad pattern commands
	shared_ptr<LightOnCommand> livingRoomLightOn = make_shared<LightOnCommand>(livingRoomLight);
	shared_ptr<LightOffCommand> livingRoomLightOff = make_shared<LightOffCommand>(livingRoomLight);


	shared_ptr<LightOnCommand> bedRoomLighton = make_shared<LightOnCommand>(bedRoomLight);
	shared_ptr<LightOffCommand> bedRoomLightOff = make_shared<LightOffCommand>(bedRoomLight);

	shared_ptr<CellingFanMediumCommand> cellingFanMedium = make_shared<CellingFanMediumCommand>(bedRoomCeilingFan);
	shared_ptr<CellingFanHightCommand> cellingFanHight = make_shared<CellingFanHightCommand>(bedRoomCeilingFan);
	shared_ptr<CellingFanOffCommand> cellingFanOff = make_shared<CellingFanOffCommand>(bedRoomCeilingFan);

	shared_ptr<StereoOnWithCDCommand> stereoCD = make_shared<StereoOnWithCDCommand>(stereo);
	shared_ptr<StereoOnWithRadioCommand> stereoRadio = make_shared<StereoOnWithRadioCommand>(stereo);
	shared_ptr<StereoOffCommand> stereoOff = make_shared<StereoOffCommand>(stereo);
	//Setting commands to incocer

	remote->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	remote->setCommand(1, bedRoomLighton, bedRoomLightOff);
	remote->setCommand(2, cellingFanMedium, cellingFanOff);
	remote->setCommand(3, cellingFanHight, cellingFanOff);
	remote->setCommand(4, stereoCD, stereoOff);
	remote->setCommand(5, stereoRadio, stereoOff);

	//executing commands
	remote->onButtonPress(0);
	remote->offButtonPress(0);
	remote->undoButtoonPress();

	remote->onButtonPress(2);
	remote->offButtonPress(2);
	remote->undoButtoonPress();

	remote->onButtonPress(5);
	remote->offButtonPress(5);
	remote->undoButtoonPress();

	return 0;

}