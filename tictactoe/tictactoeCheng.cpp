


#include<cstring>
#include<iostream>
#include<string.h>

using namespace std;

const int X_MOVE = 1;
const int O_MOVE = 2;
const int BLANK = 0;
const int X_TURN = 0 ;
const int Y_TURN = 1;
int clearboard(int board[3][3])
  {
       
    for (int row = 0; row < 3; row ++)
    {
      for (int column = 0; column < 3; column ++)
	{
	  board[row][column] == BLANK;
	}
    }
  }

int printboard(int board[3][3]) {
  for ( int row = 0; row < 3 ; row++)
    {
      char output[];
      cout << (char)('a' + row) <<"\t";
       for (int column = 0; column < 3; column ++)
	{
	  
	  if (board[row][column] == BLANK)
	    {
	      output += " \t";
	    }
	  else if (board[row][column] == X_MOVE)
	    {
	       output += "X\t";
	    }
	  else if (board[row][column] == O_MOVE)
	    {
	      output += "O\t";
	    }

	}
       cout << output << endl;
    }
  }

int main()

{
  int X_SCORE = 0;
  int Y_SCORE = 0;
  int TURN = X_TURN;
  int board[3][3];
 

  bool game = true;

  while (game == true)
    {
      memset(board, BLANK, 9); // liam's code
      cout << "\t1\t2\t3" << endl;
      
      
     
      clearboard (board);
      printboard (board); 
  string input = "";
  cin >> input;
  
  cout << input << endl;    }
  
  return 0;
    
}


  
  