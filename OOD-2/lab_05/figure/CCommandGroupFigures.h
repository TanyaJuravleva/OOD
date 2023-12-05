#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"
#include "IToolbar.h"
#include "CShapeFillColorVisitor.h"

class CCommandGroupFigures : public ICommand
{
public:
	CCommandGroupFigures(IToolbar& bar)
		: m_bar(bar)
	{
	}
	void Execute() override
	{
		auto vectorIndex = m_bar.GetIndexes();
		if ((!vectorIndex.empty()) && (vectorIndex.size() > 1))
		{
			sort(vectorIndex.begin(), vectorIndex.end());
			std::vector<IShapeDecorator*> newArr;
			CShapeComposite* newShape = new CShapeComposite;
			bool found = false;
			for (int i = 0; i < vectorIndex.size(); i++)
			{
				newShape->Add(m_bar.GetShapes()[vectorIndex[i]]);
			}
			for (int i = 0; i < m_bar.GetShapes().size(); i++)
			{
				for (int j = 0; j < vectorIndex.size(); j++)
				{
					if (i == vectorIndex[j])
					{
						found = true;
						break;
					}
				}
				if (!found)
					newArr.push_back(m_bar.GetShapes()[i]);
				else
					found = false;
			}
			m_bar.Backup();
			newArr.push_back(newShape);
			m_bar.GetShapes() = newArr;
			vectorIndex.clear();
			vectorIndex.push_back(m_bar.GetShapes().size() - 1);
			m_bar.SetNewIndexes(vectorIndex);
		}
	}
private:
	IToolbar& m_bar;
};