#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getBucket(char c, vector<vector<int>> sa);
int showSA(vector<vector<int>> input);

int sais(vector<vector<int>> &SA,string T,int size,vector<vector<int>> &sa) {

	vector<int> t(size);

	vector<int> P1, S1;

	//L,S‚ð”»’èt[i] = 1‚È‚çStype
	for (int i = size-1; i >= 0; i--) {
		if (i == size - 1) {
			t[i] = 1;
		}else if (T[i] < T[i + 1]) {
			t[i] = 1;
		}
		else if(T[i] > T[i+1]){
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
			cout << T.substr(i,T.size()-i) << ":L" << endl;
		}
		else {
			cout << T.substr(i,T.size()-i) << ":S" << endl;

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

		if (T[P1[i]] != '$') {

			int bkt = getBucket(T[P1[i]], sa);
			cout << T[P1[i]] << endl;
			cout << bkt << endl;

			for (auto itr = SA[bkt].rbegin();itr != SA[bkt].rend(); ++itr) {
				if (*itr == -1) {
					*itr = P1[i];
					break;
				}
				cout << *itr << endl;
			}
		}
	}
	/*
	for (auto i = SA.begin(); i != SA.end(); ++i) {
		for (auto j = (*i).begin(); j != (*i).end(); ++j) {
			if (*j != -1) {
				if (t[*j - 1] == 1) {

				}
				else {

				}
			}
		}
	}*/

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

int getBucket(char c, vector<vector<int>> sa) {
	for (int i = 0; i < sa.size(); i++) {
		if (sa[i][0] == c) {
			return i+1;
		}
		else {
			return -1;
		}
	}
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
			sa.push_back({ (int)(i + 'a'),0 });
		}
	}

	return 0;
}



int main(int argc, char *argv[]) {

	vector<vector<int>> SA;
	vector<vector<int>> sa;
	
	//string T = "abracadabra" ;
	string T = "mmiissiissiippii";
	string t = "";

	makeBucket(SA, T,sa);

	for (int i = 0; i < sa.size(); i++) {
		cout << i << ":";
		for (int j = 0; j < sa[i].size(); j++) {
			cout << sa[i][j] << '|';
		}
		cout << endl;
	}
	cout << "------------------" << endl;

	cout << t << endl;

	T += "$";

	for (int i = 0; i < SA.size(); i++) {
		cout << i << ":";
		for (int j = 0; j < SA[i].size(); j++) {
			cout << SA[i][j] << '|';
		}
		cout << endl;
	}

	sais(SA,T, T.size(),sa);

	for (int i = 0; i < SA.size(); i++) {
		cout << i << ":";
		for (int j = 0; j < SA[i].size(); j++) {
			cout << SA[i][j] << '|';
		}
		cout << endl;
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