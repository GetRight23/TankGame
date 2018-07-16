#pragma once

#include "Command.h"
#include "actor.h"

class MoveUpCommand : public Command
{
public:
	void execute(Actor& actor)
	{
		actor.moveUp();
	}
};

