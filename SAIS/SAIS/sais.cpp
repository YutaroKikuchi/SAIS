#include "sais.h"

using namespace std;

vector<int> getBucket(char c, vector<vector<int>> sa);
int showSA(vector<vector<int>> input);
int isUnique(vector<int> vec);
int induceSAfromSA1(vector<vector<int>> &SA, string T, vector<int> SA1, vector<vector<int>> sa, vector<int> P1,vector<int> t);
int sortLMSsub(vector<vector<int>> &SA, string T, int size, vector<vector<int>> sa, vector<int> &P1, vector<int> &type);
int constructS1(vector<vector<int>> &SA, vector<vector<int>> sa, vector<int> P1, string T, vector<int> &S1);
vector<int> getBucket_put2SA(char c, vector<vector<int>> &sa);

int sais_main(vector<vector<int>> &SA, string T, int size, vector<vector<int>> sa) {

	vector<int> LMS_index;
	vector<int> T1;
	vector<int> type;

	sortLMSsub(SA, T, size, sa,LMS_index,type);

	for (int i = 0; i < LMS_index.size(); i++) {
		cout << "P1[" << i << "]:" << LMS_index[i] << endl;
	}
	cout << endl;

	constructS1(SA, sa, LMS_index, T,T1);

	vector<int> SA1(T1.size(),-1);

	if (isUnique(T1) == 1) {
		cout << "uniq" << endl;
		for (auto i = T1.begin(); i < T1.end(); i++) {
			SA1[*i] = distance(T1.begin(), i);
		}
	}
	else {
		cout << "not uniq" << endl;
	}

	induceSAfromSA1(SA, T, SA1, sa, LMS_index,type);

	return 0;

}

int sortLMSsub(vector<vector<int>> &SA, string T, int size, vector<vector<int>> sa,vector<int> &P1,vector<int> &type) {
	vector<int> t(size);

	vector<int> S1;

	//L,S�𔻒�t[i] = 1�Ȃ�Stype
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

	type = t;

	return 0;
}


//1�Ȃ�S1�͏d�����Ă���0�Ȃ�d�����Ă��Ȃ�
int constructS1(vector<vector<int>> &SA, vector<vector<int>> sa,vector<int> P1, string T, vector<int> &S1) {

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

	vector<int> v(R.size(),-1);
	int order = 0;

	for (auto saidx = SA.begin(); saidx < SA.end(); saidx++) {
		for (auto saidx2 = (*saidx).begin(); saidx2 < (*saidx).end(); saidx2++) {
			int order_LMS = 0;
			for (auto p1idx = P1.begin(); p1idx < P1.end(); p1idx++) {
				if (*saidx2 == *p1idx) {
					if (order_LMS != 0 && R[order_LMS] == R[order_LMS - 1]) {
						v[order_LMS] = order;
					}
					else {
						v[order_LMS] = order;
						order++;
					}
				}
				order_LMS++;
			}
		}
	}
	
	cout << "**********************" << endl;
	for (auto i = R.begin(); i != R.end(); i++) {
		cout << "R[" << distance(R.begin(),i) << "]: " << *i << endl;
	}

	cout << "**********************" << endl;
	for (auto i = v.begin(); i != v.end(); i++) {
		cout << "v[" << distance(v.begin(),i) << "]: " << *i << endl;
	}

	S1 = v;

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

int induceSAfromSA1(vector<vector<int>> &SA, string T, vector<int> SA1, vector<vector<int>> sa, vector<int> P1, vector<int> t) {

	for (auto i = SA.begin(); i < SA.end(); i++) {
		for (auto j = (*i).begin(); j < (*i).end(); j++) {
			(*j) = -1;
		}
	}

	cout << endl << SA1.size() << endl << endl;

	for (auto i = SA1.rbegin(); i < SA1.rend(); i++) {
		cout << T.substr(P1[*i],T.size()) << endl;
		if (T[P1[*i]] == '$') {
			SA[0][0] = P1[*i];
		}
		else {
			vector<int> bkt = getBucket(T[P1[*i]], sa);
			for (auto itr = SA[bkt[0]].rbegin(); itr != SA[bkt[0]].rend(); ++itr) {
				cout << "bkt=" << *itr << endl << endl;
				if (*itr == -1) {
					*itr = P1[*i];
					break;
				}
			}
		}
	}

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

	showSA(SA);

	cout << "END" << endl;
	
	return 0;
}

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

vector<int> getBucket_put2SA(char c, vector<vector<int>> &sa) {
	for (int i = 0; i < sa.size(); i++) {
		if (sa[i][0] == c) {
			vector<int> returnbkt = { i + 1  ,sa[i][1],sa[i][2] };
			sa[i][2]--;
			return returnbkt;
		}
		else {

		}
	}

	return { -1 };
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

int isUnique(vector<int> vec) {

	for (auto i = vec.begin(); i < vec.end(); i++) {
		for (auto j = i + 1; j < vec.end(); j++) {
			if (*i == *j) {
				return 0;
			}
		}
	}

	return 1;
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

