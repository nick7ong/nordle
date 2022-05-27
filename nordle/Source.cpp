#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string file = "words.txt";

void fileStream(vector<string>& V, string f) {
	ifstream fin;
	fin.open(f);
	if (fin.is_open()) {
		while (!fin.eof()) {
			string w;
			fin >> w;
			V.push_back(w);
		}
	}
	else if (fin.fail()) {
		cout << "file error" << endl;
		exit(1);
	}
	fin.close();
}



int main() {
	vector<string> V;
	fileStream(V, file);
	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << "\n";
	}

}
