/*****************************************************************************/
/* Guess a Number (1-1000)                                                   */
/* Homework 1                                                                */
/* Michael Overy                                                             */
/*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void guessGame(); // Promts user to guess a randomly generated number
bool isCorrect(int, int); // Compares a guess to the answer

int main() {

  srand(time(0)); 
  guessGame();

  return 0;
}

//Generates a random number and prompts the user to guess
void guessGame() {
  
  int answer;
  int guess;
  char response;

  // Loop until the user decides to exit
  do {
    answer = 1 + rand() % 1000;

    cout << "I have a number between 1 and 1000.\n"
	 << "Can you guess my number?\n"
	 << "Please type your first guess." << endl << "? ";    
    cin >> guess;

    // Loop until user guesses correctly
    while (!isCorrect(guess, answer)) 
      cin >> guess;

    cout << "\nExcellent! You guessed the number!\n"
	 << "Would you like to play again (y or n)? ";

    cin >> response;    
    cout << endl;

  } while(response == 'y');

    return;
}

// Checks the users guess to the answer
bool isCorrect(int g, int a) {

  if(g == a)
    return true;

  if(g < a)
    cout << "Too low. Try again.\n? ";
  else 
    cout << "Too high. Try again.\n? ";

  return false;
}
