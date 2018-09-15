

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
{
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
   
    cout << "\t1\t2\t3" << endl;
        for ( int row = 0; row < 3 ; row++)
        {
          string output= "";
          cout << (char)('a' + row) <<"\t";
           for (int column = 0; column < 3; column ++)
        	{
    	    if (board[row][column] == BLANK)
    	        {
    	            output += "\t";
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
  int O_SCORE = 0;
  int TURN = X_TURN;
  int board[3][3];
 

  bool game = true;
  clearboard(board);
  cout << "Start the game by entering any of coordinates that's blank in the 3v3 board." << endl;
      cout << "With a lower case letter followed up by a number. " << endl;
  
  while (game == true)
    {
     
     printboard(board);
      if (TURN == X_TURN)
      {
  cout << "It's X's turn now " << endl;
      }
      else
      {
           cout << "It's O's turn now " << endl;
      }
  char where [2] ;
  cin.get(where, 3);
  cin.get();
    int Row = 0;
    int Column = 0;
  
       
        while (where[0]!= 'a' &&
        	where[0]!= 'b' &&
        	where[0]!= 'c' )
        		{
        				cout << "Row must be an a or b or c." << endl;
        				cin.get(where,3);
        				cin.get();
        				
        		}
        while (where[1]!= '1' &&
        		where[1]!= '2' &&
        		where[1]!= '3' )
        		{
        			cout << "Column must be a 1 or 2 or 3." << endl;
        		    cin.get(where,3);
        				cin.get();
        		}
        
        		    Row = where[0] - 'a';
        		    Column = where[1] - '1';
                   // cout << where[0]- 'a' << "," << where[1] - '1' << endl;
                    
                    if (board[Row][Column] == BLANK)
                    {
                     //   cout << where[0]- 'a' << "," << where[1] - '1' << endl;
                       
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


