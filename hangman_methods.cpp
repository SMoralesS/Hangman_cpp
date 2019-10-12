#include "hangman.h"

hangman::hangman(){
	/*Constructor, initialize the words vector and choose one word for the game*/
	createWords();
	int randWord = rand()%(words.size());
	word = words[randWord];
	for(int i=0;i<word.length();i++) guess.push_back('*');
	cont = 7;
}
void hangman::createWords(){
	/*Initialize all the pasible values for the word*/
	string a[] = {"santiago","morales","computing","physics","program","animal","hangman"}; 
	words.assign(a,a+6);
}

void hangman::deployMenu(){
	/*Show the menu to the user and save in the menu variable the option she/he choosed*/
	string senuelo;
	while(true){
		cout << "\nChoose one of the following options:\n"
			 << "1. Guess one letter\n"
			 << "2. Guess the word\n"
			 << "0. Exit" << endl;
		/*Try used for not let the user choose no valid options*/
		try{
			getline(cin,senuelo);
			for(int i=0;i<int(senuelo.length());i++){
				if(!isdigit(senuelo.at(i))) throw senuelo;
			}
			menu = atoi(senuelo.c_str());
			if(menu>4 or menu<0) throw 1;
		}
		catch(int e){
			cout << "Please introduce one of the options in the menu." << endl;
			continue;
		}
		catch(string e){
			cout << "Please introduce one of the options in the menu." << endl;
			continue;
		}
		break;
	}
}
void hangman::guessLetter(){
	/*Recive a letter from the user and if the letter is in the word change the asterisk on those positions
	for the correct letter. If not, the tries counter lows one. If it was the last letter display a winner 
	message and exit the program*/
	char letter;
	string senuelo;
	while(true){
		try{
			cout << "Introduce the letter: ";
			getline(cin,senuelo);
			if(senuelo.length()!=1 or isdigit(senuelo.at(0))) throw 1;

			if(isupper(senuelo.at(0))) letter = tolower(senuelo.at(0));
			else if(islower(senuelo.at(0))) letter = senuelo.at(0);
			else throw 1;
		}
		catch(int e){
			cout << "Please introduce (only) one letter." << endl;
			continue;
		}
		break;
	}
	int aux = 0;
	for(int i=0;i<guess.length();i++){
		if(word.at(i)==letter){
			guess.at(i)=letter;
			aux = aux + 1;
		}
	}
	if(aux==0){
		cont--;
	}
	if(guess==word){
		winnerMessage();
		exit(1);
	}
}
void hangman::guessWord(){
	/*Receive a string from the user and if is the word display a winner message and exit the program
	if is not the tries counter lows one*/
	string word_guess;
	cout << "Introduce the word: ";
	getline(cin,word_guess);
	if(word_guess==word){
		winnerMessage();
		exit(1);
	}
	else{
		cont--;
	}
}
void hangman::losserMessage(){
	cout << "You loosed!" << endl;
}
void hangman::winnerMessage(){
	cout << "Congratulations, you won!" << endl;
}
void hangman::getGuess(){
	/*Message with the current information*/
	cout << "\nWord: " << guess << setw(20) << "Attempts: " << cont << endl;
}
void hangman::play(){
	/*Principal program, is the only public method and only contents the general order*/
	while(true){
		getGuess();
		deployMenu();
		if(menu==0){
			cout << "You give up" << endl;
			losserMessage();
			exit(1);
		}
		else if(menu==1){
			guessLetter();
		}
		else{
			guessWord();
		}
		if(cont==0) {
			losserMessage();
			break;
		}
	}
}
