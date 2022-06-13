#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <cstring>
#include <random>
#include <windows.h>
#include <wincon.h>
//#include "color.hpp" // for color text 

#pragma warning(disable : 4996)
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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

string color(string c, char x) {
	string newString = c + x;
	return newString;
}

struct Element {
	string border = "+---+---+---+---+---+";
	//array<char, 21> row = { '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|' };
	array<string, 21> row = { "|", "~", "~", "~", "|", "~", "~", "~", "|", "~", "~", "~", "|", "~", "~", "~", "|", "~", "~", "~", "|"};


	void PrintBlank(int rowNum) {
		for (int i = 0; i < rowNum; i++) {
			cout << border << '\n';
			for (auto& i : row)
				cout << i;
			cout << '\n';
		} cout << border << '\n';
	}

	void ColorStoreRow(Element& r, string g, char* ca, char* cg) {
		strncpy(cg, g.c_str(), sizeof(cg) + 1);
		for (int i = 2, j = 0; i < r.row.size() + 1 && j < sizeof(cg) + 1; i += 4, j++) {
			if (ca[j] != cg[j])
				r.row[i] = color(WHITE, cg[j]);
			else if (ca[j] == cg[j])
				r.row[i] = color(GREEN, cg[j]);
		}
	}

	void PrintGuess(Element& r) {
		for (auto& i : r.row) {
			cout << RESET<< i << RESET;
		}
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
			r1.ColorStoreRow(r1, g1, ca, cg1);		
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
			r2.ColorStoreRow(r2, g2, ca, cg2);
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
			r3.ColorStoreRow(r3, g3, ca, cg3);
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
			r4.ColorStoreRow(r4, g4, ca, cg4);
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
			r5.ColorStoreRow(r5, g5, ca, cg5);
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
			r6.ColorStoreRow(r6, g6, ca, cg6);
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
