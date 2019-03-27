/*
 * file: issn.h
 *	Declarations for an Issn that represents a journal ISSN,
 *	usually displayed as nnnn-nnnC
 *
 * @date Oct 1, 2018
 * @author philip gust
 */

#ifndef ISSN_H_
#define ISSN_H_

#include <inttypes.h>

/** Represents an 8-digit journal id: nnnnnnnC */
typedef uint32_t Issn;

/** Sentinel value used when the ISSN is unknown */
extern const Issn ISSN_UNKNOWN;

/**
 * Get string representation of ISSN.
 * @param issn the ISSN value
 * @param issnChars array to receive the ISSN characters
 * @return pointer to ISSN chars as nnnn-nnnC
 */
char *issnToString(Issn issn, char issnChars[]);

/**
 * Parse string representation of Issn.
 * @param issnChars characters of ISSN as nnnn-nnnC
 * @return issn or ISSN_UNKNOWN if parse failed
 */
Issn parseIssn(const char issnChars[]);

#endif /* ISSN_H_ */
