

#include<cstring>
#include<iostream>
#include<string.h>

using namespace std;

const int X_MOVE = 1;
const int O_MOVE = 2;
const int BLANK = 0;
const int X_TURN = 0 ;
const int O_TURN = 1;

bool checkwin(int board[][3], int player )
/*  check if the user wins by one of the possibilities out of 9
 */
{
		bool win = false;
		if (board[0][0] == player &&
			board[1][0] == player &&
			board[2][0] == player )
			{
			win = true;
			}
		if (board[0][1]== player &&
			board[1][1] == player &&
			board[2][1] == player )
			{
			win = true;
			}
		if (board[0][2]== player &&
				board[1][2] == player &&
				board[2][2] == player )
				{
				win = true;
				}
		if (board[0][0]== player &&
				board[0][1] == player &&
				board[0][2] == player )
				{
				win = true;
				}
		if (board[1][0]== player &&
				board[1][1] == player &&
				board[1][2] == player )
				{
			win = true;
				}
		if (board[2][0]== player &&
				board[2][1] == player &&
				board[2][2] == player )
				{
			win = true;
				}
		if (board[0][0]== player &&
				board[1][1] == player &&
				board[2][2] == player )
				{
				win = true;
				}
		if (board[2][0]== player &&
				board[1][1] == player &&
				board[0][2] == player )
				{
			win = true;
				}
		
		return win;
	
}

bool checktie(int board[][3])
{
  /*
    if all the boards is filled, and no one has win, it's a tie
   */
    bool tie = true;
    for ( int row = 0; row < 3 ; row++)
    {
         for (int column = 0; column < 3; column ++)
         {
             if (board[row][column] == BLANK)
             {
                 tie = false;
             }
         }
    }
    return tie;
    
}
int clearboard ( int board[][3])
{// set everything on the board to blank;
       for (int row = 0; row < 3; row ++)
        {
            for (int column = 0; column < 3; column ++)
        	{
	          board[row][column] = BLANK;
	        }
             
        }
}
int printboard (int board[][3])
{
  // print out the board
  // print out the top of th eboard
    cout << "\t1\t2\t3" << endl;
        for ( int row = 0; row < 3 ; row++)
        {
	  //print out the side of the board. for each row, print a + row number.
          cout << (char)('a' + row) <<"\t";
	  // if it's blank print nothing, if it's X print X if it's O print O
           for (int column = 0; column < 3; column ++)
        	{
    	    if (board[row][column] == BLANK)
    	        {
		  cout << "\t";
    	        }
    	  else if (board[row][column] == X_MOVE)
    	        {
		  cout << "X\t" ;
	         }
    	  else if (board[row][column] == O_MOVE)
    	         {
		   cout << "O\t";
		 }
            
    	    }
	   cout << endl;
       
      
        }   
}
int main()

{
  int X_SCORE = 0;
  int O_SCORE = 0;
  int TURN = X_TURN;
  int board[3][3];
 

  bool game = true;
  clearboard(board);
  // reset everything
  cout << "Start the game by entering any of coordinates that's blank in the 3v3 board." << endl;
      cout << "With a lower case letter followed up by a number. " << endl;
  
  while (game == true)
    {
     
     printboard(board);
     //tell user whose turn it is
      if (TURN == X_TURN)
      {
  cout << "It's X's turn now " << endl;
      }
      else
      {
           cout << "It's O's turn now " << endl;
      }
      char where [2] ;  //coordinates
      char user [99]; // whatever user may enter
      int length = 0; // length
      cin.get(user,99);  //read in whatever user may enter
 cin.get();
 for (length = 0; length < strlen(user); length++)
    {
    }
 
 user[length] ='\0';  // stop reading in more
 where[0] = user[0]; // only care about the first two letter/number the user put in
  where[1] = user [1];
    int Row = 0;
    int Column = 0;
  
    // if user can't enter a correct coordinate, keep doing it. The user [99] stops the while loop from never ending
        while (where[0]!= 'a' &&
        	where[0]!= 'b' &&
        	where[0]!= 'c' )
        		{
        				cout << "Row must be an a or b or c." << endl;
        				   length = 0;
 cin.get(user,99);
 cin.get();
 for (length = 0; length < strlen(user); length++)
    {
    }
 
  user[length] ='\0';
  
   where[0] = user[0];
  where[1] = user [1];
        				
        		}
        while (where[1]!= '1' &&
        		where[1]!= '2' &&
        		where[1]!= '3' )
        		{
        	           cout << "Column must be a 1 or 2 or 3." << endl;
        		   
			    where[3] = '\0';
			    length = 0;
			   
					cin.get(user,99);
 cin.get();
 for (length = 0; length < strlen(user); length++)
    {
    }
 
  user[length] ='\0';
  where[0] = user[0];
  where[1] = user [1];        		}
        
        		    Row = where[0] - 'a';
        		    Column = where[1] - '1';
                   // cout << where[0]- 'a' << "," << where[1] - '1' << endl;
                    
                    if (board[Row][Column] == BLANK)
                    {
                     //   cout << where[0]- 'a' << "," << where[1] - '1' << endl;
		      // if the place
                        if (TURN == X_TURN)
                        {
                        
                        board[Row][Column] = X_MOVE;
                        TURN = O_TURN;
                           if (checkwin(board, X_MOVE) == 1)
                            {
                               printboard(board);
                               X_SCORE += 1;
                               cout << "X just won, the score is now: X: " <<X_SCORE<<" O: " << O_SCORE << endl;
                                
                                clearboard(board);
                                cout << "Wanna keep playing? Type \"Y\" or \"y\" to continue! " << endl; 
                                   char go [1];
                                   cin.get(go,2);
                                   cin.get();
                                   if (go[0] != 'y' && go[0] != 'Y'  )
                                   {
                                       return 0;
                                   }
                            }
                             else if (checktie(board) == 1)
                            {
                                 printboard(board);
                                   
                                    cout << "It was a tie! the score is now: X: " <<X_SCORE<<" O: " << O_SCORE << endl;
                                   
                                    clearboard(board);
                                    cout << "Wanna keep playing? Type \"Y\" or \"y\" to continue! " << endl; 
                             char go [1];
                                cin.get(go,2);
                                cin.get();
                                 if (go[0] != 'y' && go[0] != 'Y'  )
                                     {
                                    return 0;
                                      }
                                
                            }
                            
                        }
                        else if (TURN == O_TURN)
                        {
                           board[Row][Column] = O_MOVE;
                            TURN = X_TURN;
                           if (checkwin(board,O_MOVE) == 1)
                           {
                                    printboard(board);
                                    O_SCORE += 1;
                                    cout << "Y just won, the score is now: X: " <<X_SCORE<<" O: " << O_SCORE << endl;
                                   
                                    clearboard(board);
                                    cout << "Wanna keep playing? Type \"Y\" or \"y\" to continue! " << endl; 
                             char go [1];
                                cin.get(go,2);
                                cin.get();
                                 if (go[0] != 'y' && go[0] != 'Y'  )
                                     {
                                    return 0;
                                      }
                            }
                            else if (checktie(board) == 1)
                            {
                                 printboard(board);
                                   
                                    cout << "It was a tie! the score is now: X: " <<X_SCORE<<" O: " << O_SCORE << endl;
                                   
                                    clearboard(board);
                                    cout << "Wanna keep playing? Type \"Y\" or \"y\" to continue! " << endl; 
                             char go [1];
                                cin.get(go,2);
                                cin.get();
                                 if (go[0] != 'y' && go[0] != 'Y'  )
                                     {
                                    return 0;
                                      }
                                
                            }
                            
                            
                        }
                    }
                    else
                    {
                        cout << "Someone is there already!" << endl;
                    }
                 
    
    }
        
  
  
  
  
  
 
    
    
    
    

}


