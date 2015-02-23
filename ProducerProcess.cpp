/*
 * ProducerProcess.cpp
 *
 * Created on: Feb 20, 2015
 * Author: jp
 */

#include "Includes.h"
#include "SemaphoreArray.h"
#include "SharedMemory.h"

using namespace std;

int main(int argc, char** argv) {

	char* processName = argv[0];
	string id_str;

	// Si se ingresan menos argumentos de los necesarios
	if (argc < 2) {
		string msg = "Usage ";
		msg = msg + processName + " <-amountOfItemsToProduce> \n";
		Colors::writeerr(msg, RED);
		exit(EXIT_FAILURE);
	}

	int id = getpid();
	Process::announce(PRODUCER_PROCESS_NAME, id, GREEN, "initializing.");

	srand(time(NULL) * id);

	int amountOfItemsToProduce = atoi(argv[1]);


	Store* store = (Store*) SharedMemory::get(SHARED_MEMORY_ID, sizeof(Store));
	SemaphoreArray* producersSemaphore = SemaphoreArray::get(PRODUCERS_SEMAPHORE_ID);
	SemaphoreArray* consumersSemaphore = SemaphoreArray::get(CONSUMERS_SEMAPHORE_ID);


	for(int i = 0; i < amountOfItemsToProduce; i++){

		consumersSemaphore->wait();
		producersSemaphore->wait();

		sleep(Process::sleepTime());

		int newItem = Utils::generateRandomNumberBetween(1,5);
		store->item = newItem;
		if(i == amountOfItemsToProduce - 1) store->productionFinished = true;

		std::string newItemAnnouncement = "New Item: "+ Utils::intToString(newItem);
		Process::announce(processName, id, GREEN, newItemAnnouncement.c_str());

		producersSemaphore->post();
		consumersSemaphore->post();

	}

	Process::announce(PRODUCER_PROCESS_NAME, id, UNDERLINEDGREEN, "finished.");
	return 0;
}

