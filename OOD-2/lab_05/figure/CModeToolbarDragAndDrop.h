#pragma once
#include "IModeToolbar.h"
#include "IBar.h"

class CModeToolbarDragAndDrop : public IModeToolbar
{
public:
	CModeToolbarDragAndDrop(IBar& barMode)
		: m_barMode(barMode)
	{
	}
private:
	IBar& m_barMode;
};