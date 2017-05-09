#include "sais.h"

using namespace std;

int main(int argc, char *argv[]) {

	vector<int> SA;

	string T = "abracadabra";
	//	string T = "mmiissiissiippii";

	sais(SA, T);
	T += "$";

	for (auto i = SA.begin(); i != SA.end(); i++) {
		cout << "SA[" << *i << "]:\t" << T.substr(*i, T.size() - 1) << endl;
	}

	return 0;
}