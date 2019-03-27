/*
 * main.c
 *
 * Defines main function
 *
 *  Created on: Oct 1, 2017
 *  Author: philip gust, HoKang Yu/ yu2749luca (github)
 *
 *  implemented new test units for getJournalFromISSN and newJournal
 */

#include <stdio.h>
#include <stdlib.h>
#include "journal.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/**
 * Test Issn functions.
 */
static void test_issn(void) {
	char str[20];  // char array converting Issn to string
	char *s;   // conversion result pointer

	// convert ISSN to string
	Issn issn0 = 0x12345678;
	s = issnToString(issn0, str);
	CU_ASSERT_STRING_EQUAL(s, "1234-5678");

	// parse string to Issn
	Issn issn_0 = parseIssn(s);
	CU_ASSERT_EQUAL(issn0, issn_0);

	// convert  ISSN with X checksum
	Issn issn1 = 0x0034567a;
	s = issnToString(issn1, str);
	CU_ASSERT_STRING_EQUAL(s, "0034-567X");

	// parse string to Issn
	Issn issn_1 = parseIssn(s);
	CU_ASSERT_EQUAL(issn1, issn_1);

	// parse invalid ISSN
	Issn issn_2 = parseIssn("012a-5468");
	CU_ASSERT_EQUAL(issn_2, ISSN_UNKNOWN);
	// parse invalid ISSN

	Issn issn_3 = parseIssn("");
	CU_ASSERT_EQUAL(issn_3, ISSN_UNKNOWN);
}

/**
 * Test Publisher functions.
 */
static void test_publisher(void) {
	const char* pubName = "Publisher";

	// ensure publisher created
	Publisher *pub = newPublisher(pubName);
	CU_ASSERT_PTR_NOT_NULL_FATAL(pub);
	CU_ASSERT_STRING_EQUAL(pub->name, pubName);

	// ensure journals array exists and has no journals
	CU_ASSERT_PTR_NOT_NULL_FATAL(pub->journals);
	CU_ASSERT_EQUAL_FATAL(pub->nJournals, 0);

	// create four journals and ensure added to publisher
	for (int i = 0; i < 10; i++) {
		// ensure journal created
		// publisher also needs add i in order to make the function works
		Journal *jnl = newJournal("Journal", 0x12345678+i, pub);
		CU_ASSERT_PTR_NOT_NULL_FATAL(jnl);

		// ensure jnl added to journals array
		CU_ASSERT_PTR_NOT_NULL_FATAL(pub->journals);
		CU_ASSERT_EQUAL_FATAL(pub->nJournals, i+1);
		CU_ASSERT_PTR_EQUAL_FATAL(pub->journals[i], jnl);
	}

	//create a new publisher
	//input two journals with same ISSN and see if nJournal remains the same
	const char *pubName2 = "NY Time";
	Publisher *pub2 = newPublisher(pubName2);
	Journal *book2=newJournal("Book1", 0x12345900,pub2);
	book2=newJournal("Book2", 0x12345900,pub2);
	Journal *book3=newJournal("Book3", 0x12345900,pub2);
	CU_ASSERT_PTR_NOT_NULL_FATAL(pub2);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book2);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book3);
	CU_ASSERT_EQUAL_FATAL(pub2->nJournals,1);

	//test *newJournals can successfully get journals from ISSN
	const char *pubName3 = "LA Time";
	Publisher *pub3=newPublisher(pubName3);
	Issn issn=0x12345900;
	Journal *book4=newJournal("book4",issn,pub3);
	//input the same Issn with different book names to ensure no duplicates
	Journal *book5=newJournal("book5",issn,pub3);


	CU_ASSERT_PTR_NOT_NULL_FATAL(pub3);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book4);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book5);

	//return book name for book5 should be book4 because ISSN is the same
	CU_ASSERT_PTR_EQUAL_FATAL(book5->name,book4->name);
	//return joural name under pub3 is the same as first input
	CU_ASSERT_PTR_EQUAL_FATAL(pub3->journals[0]->name,book4->name);
	// # of journal should be 1 because all input have same ISSN
	CU_ASSERT_EQUAL_FATAL(pub3->nJournals,1);
	//assignment7-3
	deletePublisher(pub3);
	CU_PASS("Publisher3 deleted");



	//write journals with same names but different issn
	pub3=newPublisher(pubName3);
	//test pub3 malloc
	CU_ASSERT_PTR_NOT_NULL_FATAL(pub3);
	book4=newJournal("Lakers",issn,pub3);
	book5=newJournal("Lakers",issn+1,pub3);

	CU_ASSERT_PTR_NOT_NULL_FATAL(book4);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book5);

	//shoud have same journal name but different ISSN
	CU_ASSERT_STRING_EQUAL_FATAL(book4->name,book5->name);
	CU_ASSERT_NOT_EQUAL_FATAL(book4->issn,book5->issn);

	//assignment7-3
	deletePublisher(pub3);
	CU_PASS("Publisher3 deleted");
}

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
 * Unit test driver
 *
 * @return test error code
 */
static CU_ErrorCode test_all_local(void) {
	// initialize the CUnit test registry – only once per application
	CU_initialize_registry();

	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("test_all_local", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test_issn", test_issn);
	CU_add_test(pSuite, "test_publisher", test_publisher);
	CU_add_test(pSuite, "test_journal", test_journal);

	// run all suites using the basic interface that echoes to the console in this example
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	// display information on failures that occurred
	CU_basic_show_failures(CU_get_failure_list());

	// Clean up registry and return status
	CU_cleanup_registry();
	return CU_get_error();
}

/**
* Main program to invoke test functions
*
* @return the exit status of the unit tests
*/
int main(void) {
	// test all the functions
	CU_ErrorCode code = test_all_local();
	return (code == CUE_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}
