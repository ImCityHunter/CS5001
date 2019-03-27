/*
 * @file issn_test.c
 *
 * Test suite function for Issn.
 *
 * @date Oct 3, 2018
 * @author philip gust
 */

#include <stdio.h>
#include <stdlib.h>
#include "issn.h"
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
 * Add suite for Issn unit tests
 */
void issn_test(void) {
	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("issn_test", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test_issn", test_issn);

}
