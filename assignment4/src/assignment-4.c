/**
 * @file assignment-4.c
 *
 * This file implements a game of Tic-Tac-Toe (Naughts and Crosses).
 *
 * @date 9/19/2018
 * @author: HoKang Yu, yu2749luca (github)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * Initialize the board to space characters as empty.
 *
 * @param board the board
 */
void initBoard(char board[3][3]) {
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			board [i][j]=' ';
		}
	}
}

/**
 * Mark the board position with the marker of a player (X or O).
 *
 * @param board the board
 * @param turn the marker for a player (X or O)
 * @param boardPos the row major position on the board (1-9)
 */
void markTheBoard(char board[3][3], char turn, int boardPos) {


	//to ensure #1-3 result 0 after divided by 3
	//int row=(boardPos-1)/3;

	//to ensure the remainder is at the correct column position
	//int column=(boardPos+2)%3;
	//board [row][column]=turn;
	//char *boardp=board[0][0];
	//how come this doenst work
	*(&board[0][0] + boardPos - 1) = turn;  // row-major access
	//*((char*)board + boardPos - 1) = turn;  // row-major access

}

/**
 * Display the board.
 *
 * @param board the board.
 */
void displayBoard(char board[3][3]) {
	// YOUR CODE HERE
	printf("-------------\n");
	for (int i=0;i<3;i++){
		printf("| %c | %c | %c |\n",board[i][0],board[i][1],board[i][2]);
		printf("-------------\n");

	}
}

/**
 * Determines whether given marker has won. Only if
 * marker has three columns in ow or three rows in
 * column, or all in one of the two diagonals.
 *
 * @param board the board
 * @param marker the X or O marker
 * @return true if player with marker has won
 */
bool hasWon(const char board[3][3], char marker) {
	// YOUR CODE HERE
	bool result=false;
	for (int i=0;i<3;i++){

		//horizontal
		if (board[i][0]==marker&&board[i][1]==marker&&board[i][2]==marker){
			result=true;
		}

		//vertical
		else if (board[0][i]==marker&&board[1][i]==marker&&board[2][i]==marker){
			result=true;
		}
	}


	// diagonal left-top to right-bot
	if(board[0][0]==marker&&board[1][1]==marker&&board[2][2]==marker){result=true;}


	// diagonal right-top to left-bot
	else if(board[0][2]==marker&&board[1][1]==marker&&board[2][0]==marker){result=true;}

	return result;
}

/**
 * Determines whether there is a tie: all positions.
 * filled and no winner.
 *
 * @param board the board
 * @return true if the game is a tie, false otherwise
 */
bool isTie(const char board[3][3]) {
	bool filled=true;
	bool isTie=false;

	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			char check=board [i][j];
			if(check==' '){filled=false;
			}
		}
	}
	if(filled&&!hasWon(board,'X')){
		isTie=true;}
	return isTie;
}

/**
 * Main program for an interactive game of tic-tac-toe.
 */
int main(void) {
	char board[3][3];
	char turn = 'X';

	// initialize the board
	initBoard(board);

	printf("To play a position use the following map to enter a position.\n");
	printf("-------------\n");
	for (int boardPos = 1; boardPos <= 9; boardPos += 3) {
		printf("| %d | %d | %d |\n", boardPos, boardPos+1, boardPos+2);
		printf("-------------\n");
	}

	// play until there is a draw or a player has won
	while (!isTie(board) && !hasWon(board, 'X') && !hasWon(board, 'O')) {
		int boardPos = -1;
		bool validInput = false;

		// wait for valid input
		while(!validInput) {
			printf("Player %c, enter the position you want to play.\n", turn);
			int success = scanf("%d", &boardPos);
			if (success < 0 || boardPos < 0 || boardPos > 9 ||
				board[(boardPos-1) / 3][(boardPos-1) % 3] != ' ') {
				continue;
			}
			validInput = true;
		}

		// mark the position and display the updated board
		markTheBoard(board, turn, boardPos);

		// display the current board
		displayBoard(board);

		// other player's turn
		switch(turn) {
		case 'X':
			turn = 'O';
			break;
		case 'O':
			turn = 'X';
			break;
		}
	}
	// game over so report results
	// this order is not the most efficient
	if (isTie(board)) {
		printf("The game ends in a tie.\n");
	} else if (hasWon(board, 'X')) {
		printf("Player X has won.");
	} else {
		printf("Player O has won.");
	}
}

