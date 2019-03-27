/*
 * journal.h
 *
 * Declaration of a Journal.
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust
 */

#ifndef JOURNAL_H_
#define JOURNAL_H_

#include "issn.h"
#include "publisher.h"

typedef struct Publisher Publisher;

/** Struct that defines a Journal */
typedef struct  Journal {

	//modify to an array pointer
	char *name;			// journal name
	Issn issn;				// ISSN of journal
	Publisher *publisher;	// pointer to publisher
} Journal;

/**
 * Create and initialize a journal for a publisher.
 * @param name the journal name
 * @param issn the journal issn
 * @param publisher the journal publisher
 * @return the journal
 */
Journal *newJournal(const char *name, Issn issn, Publisher *publisher);

/**
 * Delete the journal.
 * @param journal the journal to delete
 */
void deleteJournal(Journal *journal);

/**
  * Print a Journal only without publisher info.
  * @param journal the journal to print
  */
void printJournalInfo(const Journal *journal);

/**
  * Print a Journal and its publisher
  * @param journal the journal to print
  */
void printJournal(const Journal *journal);
/**
 *
 * @param publisher
 * @param issn
 * @return NULL if Issn cannot be found
 */
Journal *getJournalForIssn(const Publisher *publisher, const Issn issn);

#endif /* JOURNAL_H_ */
