#pragma once

#ifndef _SAIS_H
#define _SAIS_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

	/* find the suffix array SA of T[0..n-1]
	use a working space (excluding T and SA) of at most 2n+O(lg n) */
	int sais(const unsigned char *T, int *SA, int *LCP, int n);

	/* find the suffix array SA of T[0..n-1] in {0..k-1}^n
	use a working space (excluding T and SA) of at most MAX(4k,2n) */
	int
		sais_int(const int *T, int *SA, int n, int k);

	/* burrows-wheeler transform */
	int
		sais_bwt(const unsigned char *T, unsigned char *U, int *A, int n);
	int
		sais_int_bwt(const int *T, int *U, int *A, int n, int k);


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* _SAIS_H */