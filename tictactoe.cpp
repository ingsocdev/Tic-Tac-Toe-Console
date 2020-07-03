
//Tom Brown 2011-2014 Tic Tac Toe 
//Feel free to use the source but I'd appreciate it if you'd link back to my blog but it's not compulsary.

#include <iostream>
#include "General Classes/Interface.h"

//The all important draw board function to display a visualization of the board on screen complete with X and O
void drawBoard(int board[][3],Interface& interface)
{
	interface.messageBox("Game Board Drawn Successfully!");
	int x,y = 0;
	for(int accumulator = 0; accumulator < 3; accumulator ++)
	{
		std::cout << "  " << accumulator;
	}
	std::cout << "\n";
	for(x = 0; x < 3; x ++)
	{
		std::cout << x;
		for(y = 0; y < 3; y ++)
		{
			//This loop draws [ ] in the place of a 0 in the array or O if the place holds 1 or X if the place 				//holds 2 
			if(board[x][y] == 0)
			{
				std::cout << "[ ]";
			}
			else if(board[x][y] == 1)
			{
				std::cout << "[O]";
			}
			else if(board[x][y] == 2)
			{
				std::cout << "[X]";
			}
		}
			std::cout << "\n";
	}
}

//Function to check whether the game is Won or Tied
bool victoryCheck(int board[][3], int playerToken,Interface& interface)
{
	bool gameWon = false;
	int positionsFilled = 0;
	for(int x = 0; x < 3; x ++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(board[x][y] != 0)
				positionsFilled ++;
		}
	}
	if(board[0][0] == playerToken && board[0][1] == playerToken && board[0][2] == playerToken)
	{
		gameWon = true;
	}
	else if(board[1][0] == playerToken && board[1][1] == playerToken && board[1][2] == playerToken)
	{
		gameWon = true;
	}
	else if(board[2][0] == playerToken && board[2][1] == playerToken && board[2][2] == playerToken)
	{
		gameWon = true;
	}
	else if(board[0][0] == playerToken && board[1][0] == playerToken && board[2][0] == playerToken)
	{
		gameWon = true;
	}
	else if(board[0][1] == playerToken && board[1][1] == playerToken && board[2][1] == playerToken)
	{
		gameWon = true;
	}
	else if(board[0][2] == playerToken && board[1][2] == playerToken && board[2][2] == playerToken)
	{
		gameWon = true;
	}
	else if(board[0][0] == playerToken && board[1][1] == playerToken && board[2][2] == playerToken)
	{
		gameWon = true;
	}
	else if(board[0][2] == playerToken && board[1][1] == playerToken && board[2][0] == playerToken)
	{
		gameWon = true;
	}
	else if(positionsFilled == 9)
	{
		interface.messageBox("It's a draw!");
		return true;
	}
	
	
	if(gameWon == true)
	{
		if(playerToken == 1)
			interface.messageBox("Player O Wins!!");
		else if(playerToken == 2)
			interface.messageBox("Player X Wins!!");
		return true;
	}
	else
		return false;
}

//This function places a value into the board array
int makeMove(bool isComputer, int playerToken, int board[][3], Interface& interface)
{
	int x,y = 0;
	bool won = false;
	bool avaliableMove = false;
	while(won == false)
	{	
		avaliableMove = false;
		if(isComputer == false)
		{		
			while(avaliableMove == false)
			{	
				interface.messageBox("Enter the X coordinate 0 - 2");
				std::cout << "Coordinate: ";
				std::cin >> x;
				while(x != 0 && x != 1 && x != 2)
				{
					std::cin >> x;
				}
				interface.messageBox("Enter the Y coordinate 0 - 2");
				std::cout << "Coordinate: ";
				std::cin >> y;
				while(y != 0 && y != 1 && y != 2)
				{
					std::cin >> y;
				}
				if(board[x][y] == 0)
					avaliableMove = true;
				else
				{
					interface.messageBox("Sorry, the coordinates you chose are filled. Please pick another");
					drawBoard(board, interface);
				}
			}
			board[x][y] = playerToken;
			drawBoard(board,interface);	
			x,y = 0;
			won = victoryCheck(board, playerToken,interface);
			if(playerToken == 1)
			{
				playerToken = 2;
			}
			else if(playerToken == 2)
			{
				playerToken = 1;
			}	
		}
		
	}
	return 0;	
}

//This function sets up the game board by creating the array and initializing it with 0's. Also gets the users choice of either X or O

int startGame(bool isComputer,Interface& interface)
{
	std::string choice = "";
	int playerToken = 0;
	int board[3][3];
	int x,y = 0;
	for(x = 0; x < 3; x ++)
	{
		for(y = 0; y < 3; y ++)
		{
			board[x][y] = 0;
		}
	}
	interface.messageBox("Which side do you wish to choose, O or X\n");
	//start macintosh compatibility edit (removal of player verification loop)
	std::cin >> choice;
	while(choice == "" || choice != "X"  && choice != "x" && choice != "O" && choice != "o")
	{
		std::cin.sync();
		std::cin >> choice;
	}
	//end macintosh compatibility edit
	if(choice == "O" || choice == "o")
			playerToken = 1;
		else if(choice == "X" || choice == "x")
			playerToken = 2;
	makeMove(isComputer, playerToken, board,interface);
	return 0;
	
}

int main()
{
	Interface interface;
	interface.toggle(true);
	int choice = 0;
	std::string restartChoice = "";
	bool restart = true;
	while(restart == true)
	{
		while(choice == 0 ||choice != 1 && choice != 2 && choice != 3)
		{
			interface.messageBox("Welcome To TicTacToe V1.0 by Tom Brown 2011\n\n1. Start Game\n2. Exit\n");
			std::cout << "Pick a number: ";
			std::cin >> choice;
		}
		if(choice == 1)
		{
			startGame(false,interface);
		}
		else if(choice == 2)
		{
			return 0;
		}
			interface.messageBox("Would you like to play again? y/n");
			std::cout << "Choice: ";
			while(restartChoice != "y" && restartChoice != "n")
			{
				std::cin >> restartChoice;
			}
			if(restartChoice == "n")
				restart = false;
			else
				restartChoice = "";
				choice = 0;
	}
			return 0;
}
