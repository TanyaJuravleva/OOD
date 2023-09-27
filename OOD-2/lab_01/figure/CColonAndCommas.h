#pragma once

#include "CDecorator.h"
#include <iostream>

class CColanAndCommas : public CDecorator
{
public:
	CColanAndCommas(std::unique_ptr<IShape>&& shape)
		: CDecorator(move(shape))
	{
	}
protected:
	std::string ToStringMarks(std::string inpStr) const override;
};