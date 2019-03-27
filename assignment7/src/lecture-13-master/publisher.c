/*
 * @file: publisher.c
 *
 *  Definition of a Publisher
 *
 * @date Oct 1, 2018
 * @author philip gust, HoKang Yu/ yu2749luca (github)
 */
#include "publisher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * Create and initialize a publisher.
 * @param name the publisher name
 * @return the publisher
 */
Publisher *newPublisher(const char *name) {
	//printf("\njournal* size: %zu\n",sizeof(Journal*));
	//printf("journal size: %zu\n",sizeof(Journal));

	Publisher *publisher = malloc(sizeof(Publisher));
	publisher->name=malloc((strlen(name)+1));
	strcpy(publisher->name, name);
	publisher->nJournals = 0;	// no journals
	publisher->maxJournals = 2;	// initially two slots available
	publisher->journals = malloc(publisher->maxJournals * sizeof(Journal*));

	//what does (journal*) mean? pointer of a journal?
	//but why set size based on pointer size, not the actual size of journal (8 vs 24)
	return publisher;
}

/**
 * Delete the publisher.
 * @param publisher the publisher to delete
 */
void deletePublisher(Publisher *publisher) {

	free(publisher->name);

	//free Journal struct
	for (int i=0;i<publisher->nJournals;i++){
		deleteJournal(publisher->journals[i]);
	}
	free(publisher->journals);	// first free dynamic array
	free(publisher);
}

/**
 * Add a journal to a publisher.
 * @param publisher the publisher
 * @param journal the journal to add
 */
void addJournalToPublisher(Publisher *publisher, Journal *journal) {
	if (publisher->nJournals >= publisher->maxJournals) {  // out of space
		publisher->maxJournals *= 2;	// double available size
		publisher->journals =			// grow storage to new available size
			realloc(publisher->journals, publisher->maxJournals * sizeof(Journal*));
	}
	publisher->journals[publisher->nJournals++] = journal;
}

/**
 * Print a Publisher only without its journals.
 * @param publisher the publisher to print
 */
void printPublisherInfo(const Publisher *publisher) {
	printf("publisher name: ’%s’\n", publisher->name);
}

/**
 * Print a Publisher and its journals.
 * @param publisher the publisher to print
 */
void printPublisher(const Publisher *publisher) {
	printPublisherInfo(publisher);
	for (int jnl = 0; jnl < publisher->nJournals; jnl++) {
		printJournalInfo(publisher->journals[jnl]);
	}
}

