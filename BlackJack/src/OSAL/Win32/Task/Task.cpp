/*
 * Task.cpp
 *
 *  Created on: 14. okt. 2016
 *      Author: Andersen
 */

#include <OSAL/Task/Task.hpp>

namespace OSAL {
namespace Task {

void Task::sleep(int milliSec)
{
	Sleep(milliSec);
}

}
}


