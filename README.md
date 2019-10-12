# Hangman_cpp
Simple hangman game programed in c++.

To compile use the command:

g++ hangman.cpp hangman_methods.cpp -o hangman.out

in a folder with the 3 files.

In the hangman.h file you will find one class:
                      
  hangman:      
  
          -Instances: vvector<string> words: Vector with all the possible words.
                      int cont: start at 7 and it loses one for every mistake of the user.
                      int menu: It allow the user to chose if exit the game, guess one letter or guess the word.
                      string word: Is the word the user have to guess.
                      string guess: Is a string where is saved the progress of the user.(* if she/he not guessed the letter yet)
          -Methods:   hangman(): Constructor, initialize word and guess.
                      void play(): Is the only public method and have the general structure of the program.
                      void createWords(): Initialize the words vector.
                      void deployMenu(): Show the menu and assign menu a value.
                      void guessLetter(): Allow the user to introduce a letter. If is in the word it change * for the letter in guess, if not count loses one.
                      bool guessWord(): Allow the user to introduce a string. If it is the word deploy winner message and exit, if not count loses one.
                      void losserMessage(): Deploy a message if the user lossed.
                      void winnerMessage(): Deploy a message if the user won.
                      void getGuess(): Deploy a message with the current guess and the attempts left.
