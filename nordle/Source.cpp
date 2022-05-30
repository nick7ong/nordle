#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

class Table {
public:
	void FileStream(vector<vector<char>>& V, string f = "NewTable.txt") { // store file int 2d vect or arr
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

	void Print() {
		//print 2d vec or arr
	}

};



void TerminalGUI(int turnRow)
{
	string guess;

	if (turnRow == 0) {
		Table T1;
		T1.FileStream(NewTable);
		T1.Print();
		cout << "Enter Guess: ";
		cin >> guess;
	}
	else if (turnRow == 1) {
		

		
		cout << "Enter Guess: ";

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
