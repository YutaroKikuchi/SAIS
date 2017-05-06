#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sais(vector<string> *SA,string T,int size) {

	vector<int> t(size);

	vector<int> P1, S1;

	//L,S‚ð”»’èt[i] = true‚È‚çS
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			t[i] = 1;
		}else if (T[i] < T[i + 1]) {
			t[i] = 1;
		}
		else {
			t[i] = 0;
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

	for (int i = 0; i < P1.size();i++) {
		if (i == P1.size() - 1) {
			cout << T[i] << endl;
		}
		else {
			cout << T.substr(P1[i], P1[i + 1]) << endl;
		}
	}


	

	for (int i = 0; i < P1.size(); i++) {
		
	}

	return 0;
}

int makeBucket(vector<vector<int>> &SA, string T) {
	vector<vector<int>> alphabet;

	for (int i = 0; i < 'z' - 'a'; i++) {
		alphabet.push_back({});
	}

	for (int i = 0; i < T.size(); i++) {
		alphabet[T[i] - 'a'].push_back(-1);
	}

	SA.push_back({ (int)T.size() });
	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i].size() != 0) {
			SA.push_back(alphabet[i]);
		}
	}

	return 0;
}



int main(int argc, char *argv[]) {

	vector<vector<int>> SA;
	
	string T = "abracadabra" ;

	makeBucket(SA, T);

	T += "$";

	for (int i = 0; i < SA.size(); i++) {
		cout << i << ":";
		for (int j = 0; j < SA[i].size(); j++) {
			cout << SA[i][j] << '|';
		}
		cout << endl;
	}
	

	//sais(&SA,T, T.size());

	return 0;
}