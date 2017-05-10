#include "sais.h"

int main() {

	vector<int> sa;
	string T = "abracadabra";

	sais(sa, T);

	T += "$";

	for (auto i = sa.begin(); i != sa.end(); i++) {
		cout << "SA[" << *i << "]:" << T.substr(*i, T.size() - 1) << endl;
	}

	vector<int> lcp;
	int l = 0;
	for (int i = 0; i < T.size(); ++i) {
		l = 0;
		while (T[sa[i] + l] == T[sa[i - 1] + l]) ++l;
		lcp.push_back(l);
	}

	cout << "---------------------------------" << endl;
	for (auto i = lcp.begin(); i != lcp.end(); i++) {
		cout << *i << endl;
	}

	
}