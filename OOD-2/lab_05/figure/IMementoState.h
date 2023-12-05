#pragma once

class IMementoState
{
public:
	virtual ~IMementoState() {}
	virtual IStateShapes* GetState() = 0;
};