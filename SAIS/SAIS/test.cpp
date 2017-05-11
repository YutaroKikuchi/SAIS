//#include "sais.h"
#include <iostream>
#include <malloc.h>
#include<string.h>
#include "sais_lcp.h"
using namespace std;

int showSA(unsigned char *t,int idx,int size) {

	cout << "SA[" << idx << "]:" << endl;
	for (int i = idx; i < size; i++) {
		cout << t[i];
	}
	cout << endl;
	return 0;
}

int main(int argc, char *argv[]) {

	cout << "start init" << endl;
	unsigned char *T;
	const char *fname;
	FILE *fp;
	int *SA;
	int *LCP;
	long n;

	/* Open a file for reading. */
	if ((fp = fopen(fname = "C:\\cygwin64\\home\\yusan\\data.txt", "rb")) == NULL) {
		fprintf(stderr, "%s: Cannot open file `%s': ", argv[0], fname);
		perror(NULL);
		exit(EXIT_FAILURE);
	}

	if (fseek(fp, 0, SEEK_END) == 0) {
		n = ftell(fp);
		rewind(fp);

		if (n < 0) {
			fprintf(stderr, "%s: Cannot ftell `%s': ", argv[0], fname);
			perror(NULL);
			exit(EXIT_FAILURE);
		}
	}
	else {
		fprintf(stderr, "%s: Cannot fseek `%s': ", argv[0], fname);
		perror(NULL);
		exit(EXIT_FAILURE);
	}

	cout << n << endl;
	T = (unsigned char *)malloc((size_t)n * sizeof(unsigned char));
	SA = (int * )malloc((size_t)(n + 1) * sizeof(int));
	LCP = (int *)malloc((size_t)n * sizeof(int));

	if ((T == NULL) || (SA == NULL) || (LCP == NULL)) {
		fprintf(stderr, "%s: Cannot allocate memory.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (fread(T, sizeof(unsigned char), (size_t)n, fp) != (size_t)n) {
		fprintf(stderr, "%s: %s `%s': ",
			argv[0],
			(ferror(fp) || !feof(fp)) ? "Cannot read from" : "Unexpected EOF in",
			argv[1]);
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	fclose(fp);

	if (n < 256) printf("%s\n", T);
	T[n - 1] = 0;
	if (n < 256) printf("%s\n", T);



	if (sais(T, SA, LCP, (int)n) != 0) {
		cout << "damedesu" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++) {
		showSA(T, SA[i], n);
	}

	cout << "*********************\n";

	for (int i = 0; i < n; i++) {
		cout << LCP[i] << endl;
	}

	return 0;
}