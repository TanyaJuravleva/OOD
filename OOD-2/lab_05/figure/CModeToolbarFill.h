#pragma once
#include "IModeToolbar.h"
#include "IBar.h"

class CModeToolbarFill : public IModeToolbar
{
public:
	CModeToolbarFill(IBar& barMode)
		: m_barMode(barMode)
	{
	}
private:
	IBar& m_barMode;
};