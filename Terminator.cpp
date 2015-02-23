/*
 * Terminator.cpp
 *
 *  Created on: May 4, 2014
 *      Author: jp
 */

#include "Includes.h"
#include "SemaphoreArray.h"
#include "SharedMemory.h"

int main(){
	SemaphoreArray::destroy(PRODUCERS_SEMAPHORE_ID);
	SemaphoreArray::destroy(CONSUMERS_SEMAPHORE_ID);
	SharedMemory::destroy(SHARED_MEMORY_ID, sizeof(Store));
    std::string msg = "Termination complete.";
    Colors::writeout(msg, UNDERLINEDGREEN);
    return 0;
}



