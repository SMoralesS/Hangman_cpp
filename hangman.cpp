#include "hangman.h"

using namespace std;

int main(){
	srand(time(0));
	hangman hangmanGame;
	hangmanGame.play();
	return 0;
}