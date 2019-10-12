#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<stdlib.h>
#include<vector>
#include<ctime>

using namespace std;

class hangman{
	public:
		hangman();
		void play();
	private:
		void createWords();
		void deployMenu();
		void guessLetter();
		void guessWord();
		void losserMessage();
		void winnerMessage();
		void getGuess();
		int cont;
		int menu;
		string word;
		string guess;
		vector<string> words;
};