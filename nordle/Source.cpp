#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <cstring>
#include <random>
#include "color.hpp" // for color text 

using namespace std;

// main library for words
vector<string> WordLibrary;

class GameWord {
public:
	// initiate filestream into vector
	void FileStream(vector<string>& V, string f = "words.txt") {
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

	void Print() {
		for (int i = 0; i < WordLibrary.size(); i++) {
			cout << WordLibrary[i] << "\n";
		}
	}

	// random selector actually works now
	string RandomWord(vector<string> const& V) {           
		random_device rd;
		mt19937 eng(rd());
		uniform_int_distribution<> distr(0, V.size() - 1);
		return V[distr(eng)];
	}
};

struct Element {
	string border = "+---+---+---+---+---+";
	array<char, 21> row = { '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|' };

	void PrintBlank(int rowNum) {
		for (int i = 0; i < rowNum; i++) {
			cout << border << '\n';
			for (auto& i : row)
				cout << i;
			cout << '\n';
		} cout << border << '\n';
	}

	void PrintGuess(Element r) {
		for (auto& i : r.row)
			cout << i;
		cout << '\n';
	}
};


void TerminalGUI(const string a)
{
	// declaration of local variables
	Element blank, r1, r2, r3, r4, r5, r6;
	string g1, g2, g3, g4, g5, g6;
	int turnRow = 0;
	int turns = 6;
	const int s = 6;
	char cg1[s], cg2[s], cg3[s], cg4[s], cg5[s], cg6[s], ca[s];

	// store random string in char array for comparison
	strncpy_s(ca, a.c_str(), sizeof(ca));
	for (auto& i : ca)
		cout << i;
	cout << '\n';

	// turn iterator
	while (turnRow <= 6) {
		if (turnRow == 0) {
			blank.PrintBlank(turns - turnRow);
			while (g1.length() != 5) {
				cout << "Enter Guess 1: ";
				cin >> g1;
				if (g1.length() == 5) {
					continue;
				}
				
			}
			// store guess 1
			strncpy_s(cg1, g1.c_str(), sizeof(cg1));
			for (int i = 2, j = 0; i < r1.row.size() + 1 && j < 6; i += 4, j++) {
				if (cg1[j] == ca[j]) {
					r1.row[i] = cg1[j];
				}
				else if (cg1[j] != ca[j]) {
					dye::white_on_red(cg1[j]);
					r1.row[i] = cg1[j];
				}
				else {
					dye::blue_on_bright_white(r1.row[i] = cg1[j]);
				}
				
			}
		}
		else if (turnRow == 1) {
			cout << blank.border << '\n';
			r1.PrintGuess(r1);
			r2.PrintBlank(turns - turnRow);
			if (g1 == a) {
				cout << "YOU WIN :D\n";
				exit(1);
			}
			else {
				while (g2.length() != 5) {
					cout << "Enter Guess 2: ";
					cin >> g2;
					if (g2.length() == 5) {
						continue;
					}
				}
			}
			// store guess 2
			strncpy_s(cg2, g2.c_str(), sizeof(cg2));
			for (int i = 2, j = 0; i < r2.row.size() + 1 && j < 6; i += 4, j++) {
				r2.row[i] = cg2[j];
			}
		}
		else if (turnRow == 2) {
			cout << blank.border << '\n';
			r1.PrintGuess(r1);
			cout << blank.border << '\n';
			r2.PrintGuess(r2);
			r3.PrintBlank(turns - turnRow);
			if (g2 == a) {
				cout << "YOU WIN :D\n";
				exit(1);
			}
			else {
				while (g3.length() != 5) {
					cout << "Enter Guess 3: ";
					cin >> g3;
					if (g3.length() == 5) {
						continue;
					}
				}
			}
			// store guess 3
			strncpy_s(cg3, g3.c_str(), sizeof(cg3));
			for (int i = 2, j = 0; i < r3.row.size() + 1 && j < 6; i += 4, j++) {
				r3.row[i] = cg3[j];
			}
		}
		else if (turnRow == 3) {
			cout << blank.border << '\n';
			r1.PrintGuess(r1);
			cout << blank.border << '\n';
			r2.PrintGuess(r2);
			cout << blank.border << '\n';
			r3.PrintGuess(r3);
			r4.PrintBlank(turns - turnRow);
			if (g3 == a) {
				cout << "YOU WIN :D\n";
				exit(1);
			}
			else {
				while (g4.length() != 5) {
					cout << "Enter Guess 4: ";
					cin >> g4;
					if (g4.length() == 5) {
						continue;
					}
				}
			}
			// store guess 4
			strncpy_s(cg4, g4.c_str(), sizeof(cg4));
			for (int i = 2, j = 0; i < r4.row.size() + 1 && j < 6; i += 4, j++) {
				r4.row[i] = cg4[j];
			}
		}
		else if (turnRow == 4) {
			cout << blank.border << '\n';
			r1.PrintGuess(r1);
			cout << blank.border << '\n';
			r2.PrintGuess(r2);
			cout << blank.border << '\n';
			r3.PrintGuess(r3);
			cout << blank.border << '\n';
			r4.PrintGuess(r4);
			r5.PrintBlank(turns - turnRow);
			if (g4 == a) {
				cout << "YOU WIN :D\n";
				exit(1);
			}
			else {
				while (g5.length() != 5) {
					cout << "Enter Guess 5: ";
					cin >> g5;
					if (g5.length() == 5) {
						continue;
					}
				}
			}
			// store guess 5
			strncpy_s(cg5, g5.c_str(), sizeof(cg5));
			for (int i = 2, j = 0; i < r5.row.size() + 1 && j < 6; i += 4, j++) {
				r5.row[i] = cg5[j];
			}
		}
		else if (turnRow == 5) {
			cout << blank.border << '\n';
			r1.PrintGuess(r1);
			cout << blank.border << '\n';
			r2.PrintGuess(r2);
			cout << blank.border << '\n';
			r3.PrintGuess(r3);
			cout << blank.border << '\n';
			r4.PrintGuess(r4);
			cout << blank.border << '\n';
			r5.PrintGuess(r5);
			r6.PrintBlank(turns - turnRow);
			if (g5 == a) {
				cout << "YOU WIN :D\n";
				exit(1);
			}
			else {
				while (g6.length() != 5) {
					cout << "Enter Guess 6: ";
					cin >> g6;
					if (g6.length() == 5) {
						continue;
					}
				}
			}
			// store guess 6
			strncpy_s(cg6, g6.c_str(), sizeof(cg6));
			for (int i = 2, j = 0; i < r6.row.size() + 1 && j < 6; i += 4, j++) {
				r6.row[i] = cg6[j];
			}
		}
		else if (turnRow == 6) {
			cout << blank.border << '\n';
			r1.PrintGuess(r1);
			cout << blank.border << '\n';
			r2.PrintGuess(r2);
			cout << blank.border << '\n';
			r3.PrintGuess(r3);
			cout << blank.border << '\n';
			r4.PrintGuess(r4);
			cout << blank.border << '\n';
			r5.PrintGuess(r5);
			cout << blank.border << '\n';
			r6.PrintGuess(r6);
			cout << blank.border << '\n';

			if (g6 == a) {
				cout << "YOU WIN :D\n";
				exit(1);
			}
			cout << '\n';
			cout << "GAME OVER!\n";
		}
		turnRow++;
	}
}

int main() {
	GameWord N;
	N.FileStream(WordLibrary);
	string answer = N.RandomWord(WordLibrary);
	TerminalGUI(answer);

	return 0;
}
