#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"
#include "IToolbar.h"
#include "CShapeFillColorVisitor.h"

class CCommandUngoupFigures : public ICommand
{
public:
	CCommandUngoupFigures(IToolbar& bar)
		: m_bar(bar)
	{
	}
	void Execute() override
	{
		m_bar.Backup();
		auto vectorIndex = m_bar.GetIndexes();
		std::vector<IShapeDecorator*> newArr;
		int ind = vectorIndex[0];
		vectorIndex.clear();
		newArr = m_bar.GetShapes()[ind]->Ungroup();
		for (int j = 0; j < newArr.size(); j++)
		{
			vectorIndex.push_back(j);
		}
		bool found = false;
		for (int i = 0; i < m_bar.GetShapes().size(); i++)
		{
			if (i == ind)
			{
				found = true;
			}
			if (!found)
				newArr.push_back(m_bar.GetShapes()[i]);
			else
				found = false;
		}
		m_bar.GetShapes() = newArr;
		m_bar.SetNewIndexes(vectorIndex);
	}
private:
	IToolbar& m_bar;
};