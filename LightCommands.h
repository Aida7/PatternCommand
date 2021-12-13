#pragma once
#include "Command.h"
#include "Light.h"

class LightOnCommand :public Command {
	shared_ptr<Light> light;
public:
	LightOnCommand(shared_ptr<Light> light) { this->light = light; }
	void execute() override { light->on(); }
	void undo() override { light->off(); }
};

class LightOffCommand : public Command {
	shared_ptr<Light> light;
public:
	LightOffCommand(shared_ptr<Light> light) { this->light = light; }
	void execute() override { light->off(); }
	void undo() override { light->on(); }	
};