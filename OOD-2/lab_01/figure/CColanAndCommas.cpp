#include "CColonAndCommas.h"
#include <iostream>

std::string CColanAndCommas::ToStringMarks(std::string inpStr) const 
{
    const char delim = ' ';
    const std::string COLON = ": ";
    const std::string COMMA = ", ";
	std::string outStr = "";
    std::vector<std::string> outVec;

    size_t start;
    size_t end = 0;

    while ((start = inpStr.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = inpStr.find(delim, start);
        outVec.push_back(inpStr.substr(start, end - start));
    }

    for (int i = 0; i < outVec.size(); i ++) 
    {
        if (i == 0)
            outStr = outStr + outVec[i] + COLON;
        else
            outStr = outStr + outVec[i] + COMMA;
    }

	return outStr;
}