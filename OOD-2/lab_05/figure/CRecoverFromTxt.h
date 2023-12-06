#pragma once
#include "IRecoverTemplate.h"
#include "IShapeDecorator.h"
#include "CBuilderCirlce.h"
#include "CBuilderRectangle.h"
#include "CBuilderTriangele.h"
#include "CBuilderGroup.h"
#include "CCreateFigureTemplate.h"
#include "IBuilderShape.h"
#include <fstream>
#include "ReverseColor.h"
#include "CONSTS.h"

class CRecoverFromTxt : public IRecoverTemplate
{
	void ReadFile() override
	{
		IShapeDecorator* shape = nullptr;
		std::string figureName;
		std::ifstream inp(NAME_TXT_FILE);
		CCreateFigureTemplate creatorShape;
		while (inp >> figureName)
		{
			shape = creatorShape.GetShape(figureName, inp);
			if (figureName == START_GROUP)
			{
				CBuilderGroup* builderShape = new CBuilderGroup();
				shape = creatorShape.CreateGroup(builderShape, inp);
			}
			arr.push_back(shape);
		}
		inp.close();
	}
};