#pragma once
#include <memory>
#include <vector>
#include "Command.h"
#include "NoCommand.h"

using namespace std;

class RemoteControl {
	vector <shared_ptr<Command>> onCommands;
	vector <shared_ptr<Command>> offCommands;
	shared_ptr<Command> undoCommand = nullptr;
public:
	RemoteControl() {
		shared_ptr<Command> noCommand = make_shared<NoCommand>();
		for (int i = 0; i < 7; i++)
		{
			onCommands.push_back(noCommand);
			offCommands.push_back(noCommand);
		}
		undoCommand = noCommand;
	}

	void setCommand(int slot, shared_ptr<Command> onCommand, shared_ptr<Command> offCommand) {
		onCommands [slot] = onCommand;
		offCommands [slot] = offCommand;
	}

	void onButtonPress(int slot) {
		onCommands[slot]->execute();
		undoCommand = onCommands[slot];
	}
	void offButtonPress(int slot) {
		offCommands[slot]->execute();
		undoCommand = offCommands[slot];
	}
	void undoButtoonPress() {
		undoCommand->undo();
	}
};

