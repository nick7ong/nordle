#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <array>
#include <cstring>

using namespace std;

// main library for words
vector<string> WordLibrary;
vector<vector<char>> NewTable;

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

	string RandomWord(vector<string> V) {           //FIX THIS: doesnt actually generate random word
		vector<string> currentVector = V;
		string randomWord;
		int randomNumber = rand() % currentVector.size();
		randomWord = currentVector.at(randomNumber);
		return randomWord;
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

void TerminalGUI(const string guessWord)
{
	cout << guessWord << '\n';
	Element blank, r1, r2, r3, r4, r5, r6;
	string g1, g2, g3, g4, g5, g6;
	int turns = 6;
	const int s = 1024;
	char cg1[s], cg2[s], cg3[s], cg4[s], cg5[s], cg6[s];

	for (int turnRow = 0; turnRow <= 6; turnRow++) {
		if (turnRow == 0) {
			blank.PrintBlank(turns - turnRow);
			cout << "Enter Guess: ";
			cin >> g1;
			
			strncpy_s(cg1, g1.c_str(), sizeof(cg1));
			for (int i = 2, j = 0; i < r1.row.size() + 1 && j < 6; i += 4, j++) {
				r1.row[i] = cg1[j];
			}	
		}
		else if (turnRow == 1) {
			cout << blank.border << '\n';
			r1.PrintGuess(r1);
			r2.PrintBlank(turns - turnRow);
			cout << "turn 2" << endl;
			cout << "Enter Guess: ";
			cin >> g2;

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
			cout << "turn 3" << endl;
			cout << "Enter Guess: ";
			cin >> g3;

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
			cout << "turn 4" << endl;
			cout << "Enter Guess: ";
			cin >> g4;

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
			cout << "turn 5" << endl;
			cout << "Enter Guess: ";
			cin >> g5;

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
			cout << "turn 6" << endl;
			cout << "Enter Guess: ";
			cin >> g6;

			strncpy_s(cg6, g6.c_str(), sizeof(cg6));
			for (int i = 2, j = 0; i < r6.row.size() + 1 && j < 6; i += 4, j++) {
				r6.row[i] = cg6[j];
			}
		}
		else if (turnRow == 6) {
			cout << '\n';
			cout << "GAME OVER!\n";
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
		}
	}
}


int main() {
	GameWord N;

	N.FileStream(WordLibrary);
	TerminalGUI(N.RandomWord(WordLibrary));

	return 0;
}
