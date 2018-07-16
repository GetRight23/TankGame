#pragma once

#include "Command.h"
#include "actor.h"

class MoveLeftCommand : public Command
{
public:
	void execute(Actor& actor)
	{
		actor.moveLeft();
	}
};

