#pragma once

struct IFlyBehavior
{
	virtual void Fly() = 0;
	virtual ~IFlyBehavior() {}
};


//class IFlyBehavior
//{
//	public:
//		virtual void Fly() const;
//};