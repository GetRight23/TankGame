#pragma once

#include "Command.h"
#include "actor.h"

class MoveDownCommand : public Command
{
public:
	void execute(Actor& actor)
	{
		actor.moveDown();
	}
};

