/*
 * @file publisher_test.c
 *
 * Test suite function for Publisher
 *
 * @date Oct 1, 2018
 * @author philip gust, HoKang Yu, yu2749luca (github)
 *
 *
 *	write test units for *newJournal
 */

#include <stdio.h>
#include <stdlib.h>
#include "publisher.h"
#include "journal.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

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
		Journal *jnl = newJournal("Journal", 0x12345678+i, pub);
		CU_ASSERT_PTR_NOT_NULL_FATAL(jnl);

		// ensure jnl added to journals array
		CU_ASSERT_PTR_NOT_NULL_FATAL(pub->journals);
		CU_ASSERT_EQUAL_FATAL(pub->nJournals, i+1);
		CU_ASSERT_PTR_EQUAL_FATAL(pub->journals[i], jnl);
	}
	//assignment7-3
	deletePublisher(pub);
	CU_PASS("Publisher1 deleted.");

	//create a new publisher
	//input two journals with same ISSN and see if nJournal remains the same
	const char *pubName2 = "NY Time";
	Publisher *pub2 = newPublisher(pubName2);
	Journal *book2=newJournal("Book1", 0x12345900,pub2);
	book2=newJournal("Book2", 0x12345900,pub2);
	Journal *book3=newJournal("Book3", 0x12345900,pub2);
	//test pub2 malloc
	CU_ASSERT_PTR_NOT_NULL_FATAL(pub2);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book2);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book3);
	CU_ASSERT_EQUAL_FATAL(pub2->nJournals,1);
	//assignment7-3
	deletePublisher(pub2);
	CU_PASS("Publisher2 deleted.");


	//test *newJournals can successfully get journals from ISSN
	const char *pubName3 = "LA Time";
	Publisher *pub3=newPublisher(pubName3);
	Issn issn=0x12345900;
	Journal *book4=newJournal("book4",issn,pub3);
	//input the same Issn with different book names to ensure no duplicates
	Journal *book5=newJournal("book5",issn,pub3);
	Journal *book6=newJournal("book6",issn,pub3);
	Journal *book7=newJournal("book7",issn,pub3);
	Journal *book8=newJournal("book8",issn,pub3);
	//test pub3 malloc
	CU_ASSERT_PTR_NOT_NULL_FATAL(pub3);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book4);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book5);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book6);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book7);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book8);
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
	book6=newJournal("Lakers",issn+2,pub3);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book4);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book5);
	CU_ASSERT_PTR_NOT_NULL_FATAL(book6);
	//shoud have same journal name but different ISSN
	CU_ASSERT_STRING_EQUAL_FATAL(book4->name,book5->name);
	CU_ASSERT_NOT_EQUAL_FATAL(book4->issn,book5->issn);
	//book names should be the same, but ISSN are different
	CU_ASSERT_STRING_EQUAL_FATAL(book4->name,book6->name);
	CU_ASSERT_NOT_EQUAL_FATAL(book4->issn,book6->issn);
	//assignment7-3
	deletePublisher(pub3);
	CU_PASS("Publisher3 deleted");







}

/**
 * Add suite for publisher unit tests
 */
void publisher_test(void) {
	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("publisher_test", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test_publisher", test_publisher);

}
