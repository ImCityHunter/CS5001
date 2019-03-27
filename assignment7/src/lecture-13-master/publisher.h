/*
 * publisher.h
 *
 * Declaration of a Publisher that includes the publisher name.
 *
 *  Created on: Oct 1, 2018
 *  Author: philip gust
 */

#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include "journal.h"

typedef struct Journal Journal;

/** Struct that defines a Journal */
typedef struct Publisher {	// “anonymous struct”
	char *name;				// name of publisher
	Journal **journals;			// array of journal pointers
	unsigned int nJournals;		// number of journals
	unsigned int maxJournals;	// maximum number of journals
} Publisher;			// only known by its typedef name

/**
 * Create and initialize a publisher.
 * @param name the name of the publisher
 * @return the Publisher
 */
Publisher *newPublisher (const char *name);

/**
 * Delete the publisher.
 * @param publisher the publisher to delete
 */
void deletePublisher(Publisher *publisher);

/**
 * Add a journal to a publisher.
 * @param publisher the publisher
 * @param journal the journal to add
 */
void addJournalToPublisher(Publisher *publisher, Journal *journal);

/**
  * Print a Publisher only without its journals.
  * @param publisher the publisher to print
  */
void printPublisherInfo(const Publisher *publisher);

/**
  * Print a Publisher and its journals.
  * @param publisher the publisher to print
  */
void printPublisher(const Publisher *publisher);

/**
  * Print a Publisher and its journals.
  * @param publisher the publisher to print
  */
void printJournalsForPublisher(const Publisher *publisher);


#endif /* PUBLISHER_H_ */
