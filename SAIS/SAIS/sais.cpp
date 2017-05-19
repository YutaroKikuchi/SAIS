#include "sais.h"

using namespace std;

vector<int> getBucket(char c, vector<vector<int>> sa);
int showSA(vector<vector<int>> input);

int sais_main(vector<vector<int>> &SA, string T, int size, vector<vector<int>> &sa) {

	vector<int> t(size);

	vector<int> P1, S1;

	//L,S‚ð”»’èt[i] = 1‚È‚çStype
	for (int i = size - 1; i >= 0; i--) {
		if (i == size - 1) {
			t[i] = 1;
		}
		else if (T[i] < T[i + 1]) {
			t[i] = 1;
		}
		else if (T[i] > T[i + 1]) {
			t[i] = 0;
		}
		else {
			t[i] = t[i + 1];
		}
	}

	for (int i = 1; i < size; i++) {

		if (t[i] == 1 && t[i - 1] == 0) {
			P1.push_back(i);
		}
	}

	for (int i = 0; i < t.size(); i++) {
		if (t[i] == 0) {
			cout << T.substr(i, T.size() - i) << ":L" << endl;
		}
		else {
			cout << T.substr(i, T.size() - i) << ":S" << endl;

		}
	}

	cout << endl;

	for (int i = 0; i < P1.size(); i++) {
		cout << T.substr(P1[i], T.size() - 1) << endl;
	}

	cout << endl;

	/*
	for (int i = 0; i < P1.size();i++) {
		if (i == P1.size() - 1) {
			cout << T[i] << endl;
		}
		else {
			cout << T.substr(P1[i], P1[i + 1]) << endl;
		}
	}*/


	for (int i = 0; i < P1.size(); i++) {

		cout << "P1[i]=" << P1[i] << endl << endl;

		if (T[P1[i]] != '$') {

			vector<int> hoge = getBucket(T[P1[i]], sa);
			int bkt = hoge[0];
			cout << T[P1[i]] << endl;
			cout << bkt << endl;

			for (auto itr = SA[bkt].rbegin(); itr != SA[bkt].rend(); ++itr) {
				cout << "bkt=" << *itr << endl << endl;
				if (*itr == -1) {
					*itr = P1[i];
					break;
				}
			}
		}
	}

	//showSA(SA);
	//showSA(sa);

	for (auto i = SA.begin(); i != SA.end(); ++i) {
		for (auto j = (*i).begin(); j != (*i).end(); ++j) {
			cout << "SA[i][j]:" << *j << endl;
			//cout << !((*j - 1) >= 0) << endl;
			if (*j - 1 >= 0) {
				if (*j != -1) {
					if (t[*j - 1] == 1) {
					}
					else {
						cout << "T[" << *j - 1 << "]=" << T[*j - 1] << endl;
						vector<int> bkt = getBucket(T[*j - 1], sa);
						cout << "bkt[0]=" << bkt[0] << " bkt[1]=" << bkt[1] << endl;
						SA[bkt[0]][bkt[1]] = *j - 1;
						sa[bkt[0] - 1][1] += 1;
					}

					cout << "----------------------" << endl;
				}
				else {

				}
			}
			else {
			}
		}
	}

	cout << "********************" << endl << endl;

	for (auto i = SA.rbegin(); i != SA.rend(); ++i) {
		for (auto j = (*i).rbegin(); j != (*i).rend(); ++j) {
			cout << "SA[i][j]:" << *j << endl;
			//cout << !((*j - 1) >= 0) << endl;
			if (*j - 1 >= 0) {
				if (*j != -1) {
					if (t[*j - 1] == 0) {
					}
					else {
						cout << "T[" << *j - 1 << "]=" << T[*j - 1] << endl;
						vector<int> bkt = getBucket(T[*j - 1], sa);
						cout << "bkt[0]=" << bkt[0] << " bkt[2]=" << bkt[2] << endl;
						SA[bkt[0]][bkt[2]] = *j - 1;
						sa[bkt[0] - 1][2] -= 1;
					}

					cout << "----------------------" << endl;
				}
				else {

				}
			}
			else {
			}
		}
	}

	vector<string> R;

	//cout << "T.substr(" << P1[0] << "," << P1[1] << "):" << T.substr(P1[0], P1[1]) << endl;
	
	auto index = P1.begin();
	while (index < P1.end()) {

		if (index+1 != P1.end()) {
			R.push_back(T.substr(*index, *(index + 1) - *index + 1));
		}
		else {
			R.push_back(T.substr(*index,1));
		}

		++index;
	}

	cout << "**********************" << endl;
	for (auto i = R.begin(); i != R.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}

/*
int putBucket(int idx, vector<vector<int>> SA, string alphabets) {
	int bkt = getBucket(T[idx], alphabets);
	for (auto i = SA[bkt].begin(); i != SA[bkt].end(); i++) {
		if (*i != -1) {
			*i = 
		}
	}
}
*/

vector<int> getBucket(char c, vector<vector<int>> sa) {
	for (int i = 0; i < sa.size(); i++) {
		if (sa[i][0] == c) {
			return { i+1  ,sa[i][1],sa[i][2]};
		}
		else {
			
		}
	}

	return {-1};
}

int makeBucket(vector<vector<int>> &SA, string T,vector<vector<int>> &sa) {
	vector<vector<int>> alphabet;

	for (int i = 0; i <= 'z' - 'a'; i++) {
		alphabet.push_back({});
	}

	for (int i = 0; i < T.size(); i++) {
		alphabet[T[i] - 'a'].push_back(-1);
		
	}

	SA.push_back({ (int)T.size() });
	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i].size() != 0) {
			SA.push_back(alphabet[i]);
			sa.push_back({ (int)(i + 'a'),0, (int)alphabet[i].size()-1 });
		}
	}

	return 0;
}

int showSA(vector<vector<int>> input) {
	for (int i = 0; i < input.size(); i++) {
		cout << i << ":";
		for (int j = 0; j < input[i].size(); j++) {
			cout << input[i][j] << '|';
		}
		cout << endl;
	}
	cout << "------------------" << endl;

	return 0;
}

int sais(vector<int> &SA, string T) {

	vector<vector<int>> SA_bucket;
	vector<vector<int>> sa_index;

	makeBucket(SA_bucket, T, sa_index);

	T += "$";

	sais_main(SA_bucket, T, T.size(), sa_index);

	for (auto i = SA_bucket.begin(); i != SA_bucket.end(); i++) {
		for (auto j = (*i).begin(); j != (*i).end(); j++) {
			SA.push_back(*j);
		}
	}

	return 0;
}

