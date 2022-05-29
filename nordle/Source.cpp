#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include "tabulate.hpp"

using namespace std;
using namespace tabulate;

// main library for words
vector<string> WordLibrary;

class GameWord {
protected:
	

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

	void PrintLibrary() {
		for (int i = 0; i < WordLibrary.size(); i++) {
			cout << WordLibrary[i] << "\n";
		}
	}
};

string stoc(char c) {
	string s(1, c);
	return s;
}

void TerminalGUI(int turnRow)
{
	Table GUI;
	string guess("");
	char* prevGuess{};

	if (turnRow == 0) {
		GUI.add_row({ " ", " ", " ", " ", " " });
		GUI.add_row({ " ", " ", " ", " ", " " });
		GUI.add_row({ " ", " ", " ", " ", " " });
		GUI.add_row({ " ", " ", " ", " ", " " });
		GUI.add_row({ " ", " ", " ", " ", " " });
		GUI.add_row({ " ", " ", " ", " ", " " });
		cout << GUI << endl;
		cout << "Enter Guess: ";
		cin >> guess;
		prevGuess = &guess[0];

	}
	else if (turnRow == 1) {
		for (int i = 0; i < guess.length() + 1; i++) {
			GUI[0][0].set_text(stoc(prevGuess[i]));
		}
		cout << "turn 2" << endl;
		cout << "Enter Guess: ";
		cin >> guess;
	}
	else if (turnRow == 2) {
		cout << "turn 3" << endl;
		cout << "Enter Guess: ";
		cin >> guess;
	}
	else if (turnRow == 3) {
		cout << "turn 4" << endl;
		cout << "Enter Guess: ";
		cin >> guess;
	}
	else if (turnRow == 4) {
		cout << "turn 5" << endl;
		cout << "Enter Guess: ";
		cin >> guess;
	}
	else if (turnRow == 5) {
		cout << "turn 6" << endl;
		cout << "Enter Guess: ";
		cin >> guess;
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
