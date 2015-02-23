/*
 * ConsumerProcess.cpp
 *
 * Created on: Feb 20, 2015
 * Author: jp
 */

#include "utils/Includes.h"

using namespace std;

int main(int argc, char** argv) {

	char* processName = argv[0];
	string id_str;

	int id = getpid();
	Process::announce(CONSUMER_PROCESS_NAME, id, PURPLE, "initializing.");

	srand(time(NULL) * id);

	Store* store = (Store*) SharedMemory::get(SHARED_MEMORY_ID, sizeof(Store));
	SemaphoreArray* producersSemaphore = SemaphoreArray::get(PRODUCERS_SEMAPHORE_ID);
	SemaphoreArray* consumersSemaphore = SemaphoreArray::get(CONSUMERS_SEMAPHORE_ID);

	bool itemsRemain;
	while(itemsRemain){

		consumersSemaphore->wait();
		producersSemaphore->wait();

		sleep(Process::sleepTime());

		if(store->productionFinished) itemsRemain = false;

		std::string newItemAnnouncement = "Received Item: "+ Utils::intToString(store->item);
		Process::announce(processName, id, PURPLE, newItemAnnouncement.c_str());

		producersSemaphore->post();
		consumersSemaphore->post();

	}

	Process::announce(CONSUMER_PROCESS_NAME, id, UNDERLINEDPURPLE, "finished.");
	return 0;
}

