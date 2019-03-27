/*
 * @file issn_test.c
 *
 * Test suite function for Journal.
 *
 * @date Oct 3, 2018
 * @author philip gust
 *
 * write test unit for *getJournalFromIssn
 */

#include <stdlib.h>
#include "publisher.h"
#include "journal.h"
#include "issn.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/**
 * Test Journal functions.
 */
static void test_journal(void) {
	const char* pubName = "Publisher";

	// ensure publisher created for use in test
	Publisher *pub = newPublisher(pubName);
	CU_ASSERT_PTR_NOT_NULL_FATAL(pub);

	const char *jnlName[] = {"Journal0", "Journal1", "Journal2", "Journal3"};
	Issn issn = 0x12345670;

	// create four journals and ensure added to publisher
	for (int i = 0; i < 4; i++) {
		// ensure journal created
		Journal *jnl = newJournal(jnlName[i], issn+i, pub);
		CU_ASSERT_PTR_NOT_NULL_FATAL(jnl);

		// ensure journal has expected field values
		CU_ASSERT_STRING_EQUAL(jnl->name, jnlName[i]);
		CU_ASSERT_EQUAL(jnl->issn, issn+i);
		CU_ASSERT_PTR_EQUAL(jnl->publisher, pub);
	}

	//test getJournalForIssn can successfully get journals from ISSN
	const char *pubName3 = "LA Time";
	Publisher *pub3=newPublisher(pubName3);
	Issn issn2=0x12345900;
	Journal *book4=newJournal("book4",issn2,pub3);
	//input the same Issn with different book names to ensure no duplicates
	Journal *book5=getJournalForIssn(pub3,issn2);
	//expect value should be the same, since ISSN are the same
	CU_ASSERT_EQUAL(book5->name,book4->name);
}

/**
 * Add suite for Journal unit tests
 */
void journal_test(void) {
	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("journal_test", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test_journal", test_journal);
}
