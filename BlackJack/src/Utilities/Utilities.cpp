/*
 * Utilities.cpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */

#include <Utilities/Utilities.hpp>
#include <sstream>
#include <cstdlib>

namespace Utilities {

std::string intToString(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

int stringToInt(std::string string)
{
	return atoi(string.c_str());
}

int nthOccurrence(const std::string& str, const std::string& findMe, int nth)
{
    size_t  pos = 0;
    int     cnt = 0;

    while( cnt != nth )
    {
        pos+=1;
        pos = str.find(findMe, pos);
        if ( pos == std::string::npos )
            return -1;
        cnt++;
    }
    return pos;
}

}


