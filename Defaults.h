/*
 * Defaults.h
 *
 *  Created on: Apr 25, 2014
 *      Author: jp
 */

#ifndef DEFAULTS_H_
#define DEFAULTS_H_

#define PATH "/home/"

#define PRODUCER_PROCESS_NAME "ProducerProcess"
#define CONSUMER_PROCESS_NAME "ConsumerProcess"

#define PRODUCERS_SEMAPHORE_ID 14
#define CONSUMERS_SEMAPHORE_ID PRODUCERS_SEMAPHORE_ID+1
#define SHARED_MEMORY_ID CONSUMERS_SEMAPHORE_ID+1

#define SLEEP_TIME_MAX 6
#define SLEEP_TIME_MIN 4
#endif /* DEFAULTS_H_ */
