/*
 * journal.c
 *
 *  Definition of a Journal
 *
 *  Created on: Oct 31, 2017
 *  Author: philip gust,HoKang Yu/ yu2749luca (github)
 */

#include "journal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Create and initialize a journal for a publisher.
 * @param name the journal name
 * @param issn the journal issn
 * @param publisher the journal publisher
 * @return the journal
 */
Journal *newJournal(const char *name, Issn issn, Publisher *publisher) {
	Journal *journal = malloc(sizeof(Journal));
	journal->name=malloc((strlen(name)+1));

	Journal *checkJournal = getJournalForIssn(publisher, issn);
	if(checkJournal==NULL){
		strcpy(journal->name, name);
		journal->issn = issn;
		journal->publisher = publisher;
		addJournalToPublisher(publisher, journal);
		return journal;
	}
	else {
		return checkJournal;
	}
}

/**
 * Delete the journal.
 * @param journal the journal to delete
 */
void deleteJournal(Journal *journal) {
	free(journal->name);
	free(journal);
}

/**
  * Print a Journal only without publisher info.
  * @param journal the journal to print
  */
void printJournalInfo(const Journal *journal) {
	char issnChars[10];
	char* issnString = issnToString(journal->issn, issnChars);
	printf("journal name: '%s'\nISSN: %s\n", journal->name, issnString);
}

/**
  * Print a Journal and its publisher
  * @param journal the journal to print
  */
void printJournal(const Journal *journal) {
	printJournalInfo(journal);
	printPublisherInfo(journal->publisher);
}
/**
 *
 * @param publisher
 * @param issn
 * @return
 */

Journal *getJournalForIssn(const Publisher *publisher, const Issn issn){
	Journal *result=NULL;
	for (int i=0;i<publisher->nJournals;i++){
		if(publisher->journals[i]->issn==issn){

			//printf("test journal [%d] check: %u \n",i,publisher->journals[i]->issn);
			//printf("test journal find: %u \n",issn);
			result=publisher->journals[i];
			break;
		}
	}

	return result;
}
