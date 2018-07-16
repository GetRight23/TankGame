#pragma once
#include "Command.h"
#include "actor.h"

class MoveRightCommand : public Command
{
public:
	void execute(Actor& actor)
	{
		actor.moveRight();
	}
};

