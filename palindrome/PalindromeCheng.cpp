/*Chengfeng Tang's Palindrome program
user types in a sentence and if all the letters and numbers are the same backward 
tell the user that it's a palindrome
vice versa
 */
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
  
  char chArray[80];   // user's input
  char chArray2 [80];  // without punctuations and spaces
  char chArray3 [80];  //backward of chArray2 
  cout <<"Please input something and I will check if it's a palindrome for you." << endl;
  cout <<"Your sentence: " ;
  cin.get(chArray , 80);
  cin.get();
  int xd  = 0;
  for (int i = 0; i < strlen(chArray); i++)  // go through user's input and put all the letters into character array 2 and uppercase them
    {
      if ((chArray[i] >= 'a' && chArray[i] <= 'z') || (chArray[i] >= 'A' && chArray[i] <= 'Z'))
	{  // if the character is a number or a letter
	 
	  chArray2[xd++] = toupper(chArray[i]); // put it into the second character array, or capitalize it then put it
	  // in the second character array
	    
	}
        if (chArray[i] >= '0' && chArray[i] <= '9')
	    {
	      chArray2[xd++] = chArray[i];
	    }
	  
   }
  chArray2[xd] = '\0';  // puts a null in the character array and stop reading in more characters
  if (strlen(chArray2) == 0) // if user did not type either a charcter nor a number, end
    {
      cout << "Please type something that contains at least one letter please!" << endl;
      return 0;
    }
  cout <<"Input: "<<  chArray2 << endl; // print out the sentence with only letters+numbers
  int ch3tracker = 0;
  for ( int i = strlen(chArray2)-1 ; i > -1; i--) // put the charray 2 backward into charray3
    {
      chArray3[ch3tracker] = chArray2[i];
      ch3tracker ++;
    }
  chArray3[ch3tracker] = '\0'; // end charray3
  cout <<"Output: " <<chArray3 << endl; // print it out

  if ( strcmp (chArray2 , chArray3) == 0) // if they are the same backward and foward
     {
       cout << "Palindrome" << endl; // it's a palindrome
     }
  else // other wise not
     {
       cout << "Not a Palindrome" << endl;
     }
   

  return 0; //end
      

  
}
