/*
 * @file: issn.c
 *
 * Definition of an ISSN that represents a journal ISSN, usually
 * displayed as nnnn-nnnC
 *
 * @date: Oct 1, 2018
 * @author philip gust
 */

#include "issn.h"
#include <stdio.h>

/** Sentinel value used when the ISSN is unknown */
const Issn ISSN_UNKNOWN = 0;	// value is not a valid ISSN

/**
 * Get string representation of ISSN.
 * @param issn the ISSN value
 * @param issnChars array to receive the ISSN characters
 * @return pointer to ISSN chars as nnnn-nnnC
 */
char *issnToString(Issn issn, char issnChars[]) {
	// make use of underlying uint32_t type of ISSN internally
 	sprintf(issnChars, "%04x-%04x", issn >> 16, issn & 0xFFFF);
 	if (issnChars[8] == 'a') {
		issnChars[8] = 'X';  // issn uses ‘X’ rather than ‘a’ for 10
	}
	return issnChars;
}

/**
 * Parse string representation of Issn.
 * @param issnChars characters of ISSN as nnnn-nnnC
 * @param issnChars array to receive the ISSN characters
 * @return issn or ISSN_UNKNOWN if parse failed
 */
Issn parseIssn(const char issnChars[]) {
	unsigned d[8];

	int n = sscanf(issnChars, "%1u%1u%1u%1u-%1u%1u%1u%1u",
					&d[0],&d[1],&d[2],&d[3],&d[4],&d[5],&d[6],&d[7]);
	if ((n == 7) && (issnChars[8] == 'X')) {
		d[n++] = 0xa;
	}
	Issn issn = 0;
	if (n == 8) {
		for (int i = 0; i < 8; i++) {
			issn = issn<<4 | d[i];
		}
	}
	return issn;
}
