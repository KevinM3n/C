#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//Chengfeng Tang's guessing game
// Guess a number and if u get it right u get it right
// else u get it wrong
int main ()
{
  int input = 0 ; //read in the input
  int guess = 0; // keep track of the number of guesses
  int idk =0; // to see if user wants to play again
  bool game = true;
  int randomnumber = 0;

  while ( game == true) // the game won't end until user gets it right and says no when being asked to play again
  {
    if

      (guess==0)
      {
  cout << " Please guess a random number!" << endl; // tell user to guess a number

  
  
  srand(time(NULL));
  randomnumber = 0 + rand() % 101;
  cout << "number is " << randomnumber << endl;
      }
  cin >> input; // read in the number user just typed in
  guess ++; // the number of guesses user has used
    // cout << input << endl;
  if ( input < randomnumber) // if the number guessed is smaller tell user to guess something bigger
      {
	cout << "Guess something bigger"<< endl;
       
      }
  else if ( input > randomnumber) // opposite here
      {
	cout << "Guess something smaller"  << endl;
	
      }
  if (input == randomnumber)  // if user gets it right ask if the user wants to play again
      {
  cout << "Congratulations, it took you " << guess << " guesses to find out the right number. Do you want to keep playing? 1 = yes, 2 = no" << endl;
  cin >> idk;
  if ( idk == 1)  // if the user wants to keep playing resets the guesses and the user's input 
		   {
		     
		     guess = 0;
		     input = 0;
		   }
  else  // else exit the game
		   {
		     game = false;  
		     return(0);
		   }

      }
  }   
 
  
 
}
