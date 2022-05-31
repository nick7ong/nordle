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

};

struct Table {
	string border = "+---+---+---+---+---+";
	array<char, 21> blankrow = { '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|' };
	array<char, 21> guessrow = { '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|', '~', '~', '~', '|' };

	int blank = 6;
	int guess = 0;

	/*void FileStream(vector<vector<char>>& V, string f = "NewTable.txt") { // store file int 2d vect or arr
		ifstream fin;
		fin.open(f);
		if (fin.is_open()) {
			while (!fin.eof()) {
				char w;
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
	*/

	void PrintGuess() {
		for (int i = 0; i < guess; i++) {
			cout << border << '\n';
			for (auto& i : guessrow)
				cout << i;
			cout << '\n';
		} cout << border << '\n';

	}

	void PrintBlank() {
		for (int i = 0; i < blank; i++) {
			cout << border << '\n';
			for (auto& i : blankrow)
				cout << i;
			cout << '\n';
		} cout << border << '\n';

	}

};





void TerminalGUI(int turnRow)
{
	Table T;
	string g1, g2, g3, g4, g5, g6;

	if (turnRow == 0) {
		
		T.PrintBlank();
		cout << "Enter Guess: ";
		cin >> g1;

		//get this to work global
		char cg1[1024];
		strncpy_s(cg1, g1.c_str(), sizeof(cg1));
		cg1[sizeof(cg1) - 1] = 0;

		for (int i = 2 , j = 0; i < T.guessrow.size() + 1 && j < 6; i += 4, j++) {
			T.guessrow[i] = cg1[j];
		}

		

		T.blank--;
		T.guess++;
	}
	else if (turnRow == 1) {
		for (auto& i : T.guessrow)
			cout << i;
		T.PrintBlank();

		cout << "turn 2" << endl;
		cout << "Enter Guess: ";
		cin >> g2;
	}
	else if (turnRow == 2) {
		cout << "turn 3" << endl;
		cout << "Enter Guess: ";
		cin >> g3;
	}
	else if (turnRow == 3) {
		cout << "turn 4" << endl;
		cout << "Enter Guess: ";
		cin >> g4;
	}
	else if (turnRow == 4) {
		cout << "turn 5" << endl;
		cout << "Enter Guess: ";
		cin >> g5;
	}
	else if (turnRow == 5) {
		cout << "turn 6" << endl;
		cout << "Enter Guess: ";
		cin >> g6;
	}
	else if (turnRow == 6) {
		cout << "GAME OVER!" << endl;
	}

}

void IterateTurn(int turnCount) {
	while (true) {
		TerminalGUI(turnCount);
		turnCount++;
	}
}


int main() {
	GameWord N;
	int turn = 0;

	N.FileStream(WordLibrary);
	IterateTurn(turn);

	return 0;
}
