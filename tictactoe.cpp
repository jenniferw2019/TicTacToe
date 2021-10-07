/*
This program allows two players to play tic-tac-toe
The board will be reset after each game and the number of wins will be shown.
Author: Jennifer Wang
Date: 10/3/21
 */
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void clearBoard(int pBoard[][3]);
void printBoard(int pBoard[][3]);
bool checkWin(int pPlayer, int pBoard[][3]);
bool checkTie(int pBoard[][3]);

const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

int main ()
{
  
  int board[3][3];
  char input[2];
  int turn = X_TURN;
  int xWins = 0;
  int oWins = 0;
  char yesno = 'a';
  bool stillPlaying = true;

  clearBoard(board);
  
  while (stillPlaying == true)
    {
  
      while (checkWin(X_MOVE, board) == false && checkWin(O_MOVE, board)  == false && checkTie(board) == false)
  	{
	  printBoard(board);
	  cin.get(input, 3);
	  cin.get();

	  //enter a1, a2, a3, b1, b2, b3, c1, c2, c3
	  if (input[0] !='a' && input[0] != 'b' && input[0] != 'c')
	    {
	      cout << "Row must be an a, b, or c" << endl;
	    }
	  else  if (input[1] != '1' && input[1] != '2' && input[1] != '3')
	    {
	      cout << "Column must be an 1, 2, or 3" << endl;
	    }
	  
	  else
	    {
	      int row = input[0] - 'a';
	      int column = input[1] - '1';
	      if (board[row][column] == BLANK)
		{
		  if (turn == X_TURN)
		    {
		      board[row][column] = X_MOVE;
		      turn = O_TURN;
		    }
		  else
		    {
		      board[row][column] = O_MOVE;
		      turn = X_TURN;
		    }	  
		}
	      else
		{
		  cout << "There is already a piece there!" << endl;
		}
	    } 
	  
	}


      //if X wins, number of points for X increases by 1
      if (checkWin(X_MOVE, board) == true)
	{
	  printBoard(board);//prints the last move on the board
	  xWins = xWins + 1;
	  cout << "X wins!" << endl;
	  cout << "Number of O wins = " << oWins << endl;
	  cout << "Number of X wins = " << xWins << endl;
	}

      // if O wins, number of points for O increases by 1
      else  if (checkWin(O_MOVE, board) == true)
	{
	  printBoard(board); //prits the last move on the board
	  oWins = oWins + 1;
	  cout << "O wins!" << endl;
	  cout << "Number of O wins = " << oWins << endl;
	  cout << "Number of X wins = " << xWins << endl;
	}

      // if its a tie, no points are added
      else  if (checkTie(board) == true)
	{
	  printBoard(board);// prints the last move on the board
	  xWins = xWins + 0;
	  oWins = oWins + 0;
	  cout << "There is a tie!" << endl;
	  cout << "Number of O wins = " << oWins << endl;
	  cout<< "Number X wins =" << xWins << endl;
	}

      //asks players if they want to play again. if yes, board is cleared and game continues
      cout << "Play again? Type 'y' for yes and 'n' for no" << endl;
      cin >> yesno;
      cin.get();
      if (yesno == 'y')
	{
	  stillPlaying = true;
	  clearBoard(board);
	  turn = X_TURN;//resets turn to X turn
	}
      else 
	{
	  stillPlaying = false;  
	}
    }
      
  
  return 0;
}

//clearns the board after the game
void clearBoard(int pBoard[][3])
{
  
  for(int row = 0; row < 3; row++)
    {
      for (int column = 0; column < 3; column++)
	{
	  pBoard[row][column] = BLANK;
	}
    }
}

void printBoard(int pBoard[][3]) //prints the board
{
  cout << " \t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) // columns 1, 2, 3, and row a, b, and c
    {
      cout <<(char)('a' + row) << "\t";
      
      for (int column = 0; column < 3; column++)
	{
	  if (pBoard[row][column] == BLANK) // if blank, print a space
	    {
	      cout << " \t";
	    }
	  else if (pBoard[row][column] == X_MOVE) // if x move, print X
	    {
	      cout << "X\t";
	    }
	  else if (pBoard[row][column] == O_MOVE) // if O move, print O
	    {
	      cout<< "O\t";
	    }
	}
      cout << endl;
       
    }
  
}

bool checkWin(int pPlayer, int pBoard[][3])
// checking to see if there is a win (three in a row): three rows, three columns, and two diagonals
{
  
  if (pBoard[0][0] == pPlayer && pBoard[0][1] == pPlayer && pBoard[0][2] == pPlayer)
    {
      return true;
    }
  if (pBoard[1][0] == pPlayer && pBoard[1][1] == pPlayer && pBoard[1][2] == pPlayer)
    {
      return true;
    }
  if (pBoard[2][0] == pPlayer && pBoard[2][1] == pPlayer && pBoard[2][2] == pPlayer)
    {
      return true;
    }
  if (pBoard[0][0] == pPlayer && pBoard[1][0] == pPlayer && pBoard[2][0] == pPlayer)
    {
      return  true;
    }
  if(pBoard[0][1] == pPlayer && pBoard[1][1] == pPlayer && pBoard[2][1] == pPlayer)
    {
      return true;
    }
  if(pBoard[0][2] == pPlayer && pBoard[1][2] == pPlayer && pBoard[2][2] == pPlayer)
    {
      return true;
    }
  if (pBoard[0][0] == pPlayer && pBoard[1][1] == pPlayer && pBoard[2][2] == pPlayer)
    {
      return true;
    }
  if (pBoard[0][2] == pPlayer && pBoard[1][1] == pPlayer && pBoard[2][0] == pPlayer)
    {
      return true;
    }
  
  else
    {
      return false;
    }
}

bool checkTie(int pBoard[][3]) // check if there is a tie (any blanks)
{
  for (int row = 0; row < 3; row++)
    {
      for (int column = 0; column < 3; column++)
	{
	  if (pBoard[row][column] == BLANK)
	    {
	      return false;
	    }
	}
    }
  return true;
}
