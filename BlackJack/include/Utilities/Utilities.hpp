/*
 * Utilities.hpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */

#ifndef INCLUDE_UTILITIES_UTILITIES_HPP_
#define INCLUDE_UTILITIES_UTILITIES_HPP_

#include <string>

namespace Utilities {

	std::string intToString(int value);
	int stringToInt(std::string string);
	int nthOccurrence(const std::string& str, const std::string& findMe, int nth);
}

#endif /* INCLUDE_UTILITIES_UTILITIES_HPP_ */
