#pragma once
#include "Command.h"
using namespace std;

class NoCommand : public Command {
public:
	void execute() override { return; };
	void undo() override { return; };
};