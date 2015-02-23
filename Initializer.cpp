/*
 * Initializer.cpp
 *
 * Created on: May 10, 2014
 * Author: jp
 */

#include "utils/Includes.h"

using namespace std;

int main(int argc, char** argv) {

	char* programName = argv[0];
	int id = getpid();
	stringstream ss;

	// Si se ingresan menos argumentos de los necesarios
	if (argc < 3) {
		string msg = "Usage ";
		msg = msg + programName + " <-amountOfProducers> <-amountOfConsumers> \n";
		Colors::writeerr(msg, RED);
		exit(EXIT_FAILURE);
	}

	int amountOfProducers = atoi(argv[1]);
	int amountOfConsumers = atoi(argv[2]);

	Store* store = (Store*) SharedMemory::create(SHARED_MEMORY_ID, sizeof(Store));
	SemaphoreArray::create(PRODUCERS_SEMAPHORE_ID);
	SemaphoreArray::create(CONSUMERS_SEMAPHORE_ID);
	Process::announce(programName, id, LIGHTBLUE, "ipcs succesfully created.");



	Process::createProcesses(PRODUCER_PROCESS_NAME, amountOfProducers);
	Process::createProcesses(CONSUMER_PROCESS_NAME, amountOfConsumers);
	Process::announce(programName, id, LIGHTBLUE, "inicialization complete.");

}

