#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getBucket(char c, string alphabets);

int sais(vector<vector<int>> &SA,string T,int size,string alphabets) {

	vector<int> t(size);

	vector<int> P1, S1;

	//L,S‚ð”»’èt[i] = 1‚È‚çS
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
	

	cout << alphabets << endl;
	for (int i = 0; i < P1.size(); i++) {

		if (T[P1[i]] != '$') {

			int bkt = getBucket(T[P1[i]], alphabets);
			cout << T[P1[i]] << endl;
			cout << bkt << endl;

			for (auto itr = SA[bkt].rbegin();itr != SA[bkt].rend(); ++itr) {
				if (*itr == -1) {
					*itr = P1[i];
					break;
				}
				//cout << *itr << endl;
			}
		}
	}

	return 0;
}

int getBucket(char c, string alphabets) {
	for (int i = 0; i < alphabets.size(); i++) {
		if (alphabets[i] == c) {
			return i + 1;
		}
		else {
			return -1;
		}
	}
}

int makeBucket(vector<vector<int>> &SA, string T,string *t) {
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
			*t += (char)(i + 'a');
		}
	}

	return 0;
}



int main(int argc, char *argv[]) {

	vector<vector<int>> SA;
	
	//string T = "abracadabra" ;
	string T = "mmiissiissiippii";
	string t = "";

	makeBucket(SA, T,&t);

	cout << t << endl;

	T += "$";

	for (int i = 0; i < SA.size(); i++) {
		cout << i << ":";
		for (int j = 0; j < SA[i].size(); j++) {
			cout << SA[i][j] << '|';
		}
		cout << endl;
	}

	sais(SA,T, T.size(),t);

	for (int i = 0; i < SA.size(); i++) {
		cout << i << ":";
		for (int j = 0; j < SA[i].size(); j++) {
			cout << SA[i][j] << '|';
		}
		cout << endl;
	}

	return 0;
}