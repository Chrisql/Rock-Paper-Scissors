#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

// Assiging all the things below
string botDecision, inputedString, tryAnswer;
char inputed;
int botRand;

void randomizer() { // This is used to get a random number
  
    srand(time(NULL)); // Setting the seed
  botRand = rand() % 6; // Assiging the random number to botRand

  // Checking too what the bot's decision should be 
    if (botRand < 2) {
      botDecision = "Rock";      
    // if the number is less than 2 the bot's decision is "rock"
  }
  else if (botRand >= 2 && botRand < 4) { 
      botDecision = "Paper";
    // if the number >= 2 and is less than 4 the bot's decision is "paper'
    }
  else if (botRand >= 4 && botRand <= 6) {
      botDecision = "Scissors";
    // if the number is great than or equal to 4 and is less than or equal to 6 the bot's decision is "scissors"
  }
}

void askUser(){ // This is used to decided what the user pick's
  cout << "Welcome to the rock of the paper of the scissors!\n" << "choose your weapon (r for rock p for paper s for scissors)\n";
  cin >> inputed;

  if(inputed == 'r') {
    inputedString = "Rock";
  }
  else if(inputed == 'p') {
    inputedString = "Paper";
  }
  else if(inputed == 's') {
    inputedString = "Scissors";
  }
}

void winChecker() { // This function decided whether or not the user won match against the bot or not
  if (inputedString == "Rock" && botDecision == "Paper") {
    cout << "You Lose\n";
  }
  else if (inputedString == "Paper" && botDecision == "Rock") {
    cout << "You Win\n";
  }
  else if (inputedString == "Scissors" && botDecision == "Rock") {
    cout << "You Lose\n";
  }
  else if (inputedString == "Rock" && botDecision == "Scissors") {
    cout << "You Win\n";
  }
  else if (inputedString == "Paper" && botDecision == "Scissors") {
    cout << "You Lose\n";
  }
  else if (inputedString == "Scissors" && botDecision == "Paper") {
    cout << "You Win\n";
  }
}


int main() {
  begin: // if th user wants to try again jumps back up to this
askUser(); // look above to see what this does

  // Outputs what the user inputed
  cout << "You inputed: " + inputedString << endl;

  // Checks to see whether or not the user inputed 'r' or 'p' or 's'
  if (inputed =='r' || inputed =='p' || inputed == 's'){
    randomizer(); // Go to the function above to know what this does
      cout << "Bot inputed: " + botDecision << endl;

    if (inputedString == botDecision) { // checks to see whather ot not the user input is the same as the bots input
      cout << "Game Tied" << endl;
    }
    else {
      winChecker(); // Go to the functions to see what this does
    }
    // Asking the user whether or not they want to try again
    cout << "do you want to try again?(yes or no)\n";
      cin >> tryAnswer;
        cout << "\n" << endl; // Just putting a spacing

    // if the user wants to try again then jumps back to "begin: "
    if(tryAnswer == "yes" || tryAnswer == "Yes") {
      goto begin; // ^
    }
    else {
      cout << "Program ended\n";
    }
  }
    // if the user did not input 'r' or 'p' or 's' let's them know that there input is incorrect
   else if (inputed !='r' || inputed !='p' || inputed !='s') {
    cout << "incorrect input you need to input 'r' or 'p' or 's'\n";
  } 
}
