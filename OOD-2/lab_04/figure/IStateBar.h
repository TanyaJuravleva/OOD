#pragma once
class IStateBar
{
public:
	virtual void ChangeDD() = 0;
	virtual void ChangeF() = 0;
	virtual ~IStateBar() = default;
};