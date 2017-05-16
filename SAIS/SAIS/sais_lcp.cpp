#include "sais.h"

int lcp(string T, vector<vector<int>> &SA, vector<int> LMS, vector<int> LMS_LCP, vector<int> &LCP, vector<vector<int>> sa_idx);
vector<int> getBucket(char c, vector<vector<int>> sa);

int main(int argc, char *argv[]) {

	string T = "abracadabra";
	vector<vector<int>> SA_bucket;
	vector<vector<int>> SA_idx;
	makeBucket(SA_bucket, T, SA_idx);


	showSA(SA_bucket);
	showSA(SA_idx);


	return 0;
}

int calcLCP_LMS(vector<vector<int>> LMS) {


}

int lcp(string T,vector<vector<int>> &SA, vector<int> LMS ,vector<int> LMS_LCP, vector<int> &LCP, vector<vector<int>> sa_idx) {


	for (auto i = LMS.begin(); i != LMS.end(); i++) {

		cout << "P1[" << distance(LMS.begin(), i) << "]:" << *i << endl;

		if (T[*i] != '$') {

			vector<int> hoge = getBucket(T[*i], sa_idx);
			int bkt = hoge[0];
			cout << T[*i] << endl;
			cout << bkt << endl;

			for (auto itr = SA[bkt].rbegin(); itr != SA[bkt].rend(); ++itr) {
				cout << "bkt=" << *itr << endl << endl;
				if (*itr == -1) {
					*itr = *i;
					break;
				}
			}
		}

		LCP[*i] = LMS_LCP[distance(LMS.begin(), i)];
	}

	return 0;
}

vector<int> getBucket(char c, vector<vector<int>> sa) {
	for (int i = 0; i < sa.size(); i++) {
		if (sa[i][0] == c) {
			return { i + 1  ,sa[i][1],sa[i][2] };
		}
		else {

		}
	}

	return { -1 };
}

/*
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

	
}*/