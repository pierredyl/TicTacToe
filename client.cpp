//Code by Dylan Pierre
//07/23/2022

#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

const int BOARD_SIZE = 3;

void promptMessage();
void createBoard(char gameBoard[][BOARD_SIZE]);
void printBoard(char gameBoard[][BOARD_SIZE]);
void getPlayers(Player&, Player&);
bool enterGame(char gameBoard[][BOARD_SIZE], Player&, Player&);
bool testBoard(char gameBoard[][BOARD_SIZE], Player&);
bool playersTurn(char gameBoard[][BOARD_SIZE], Player&);



int main() {

	Player playerOne, playerTwo;
	char userInput;
	char gameBoard[BOARD_SIZE][BOARD_SIZE];
	promptMessage();
	getPlayers(playerOne, playerTwo);
	createBoard(gameBoard);
	enterGame(gameBoard, playerOne, playerTwo);
	printBoard(gameBoard);

	do {
		cout << "Would you like to play again? Y for yes, N for no" << endl;
		cin >> userInput;
		if (userInput == 'Y') {
			cout << playerOne.getName() << " has " << playerOne.getWinCount() << " wins" << endl;
			cout << playerTwo.getName() << " has " << playerTwo.getWinCount() << " wins" << endl;
			createBoard(gameBoard);
			enterGame(gameBoard, playerOne, playerTwo);
			printBoard(gameBoard);
		}
	} while (userInput != 'N');


	return 0;
}







//Get each players name and symbol
void getPlayers(Player& playerOne, Player& playerTwo) {
	cout << "\n\nOkay lets start by getting Player 1" << endl;
	string name;
	char symbol;
	cout << "What is your name?" << endl;
	cin >> name;
	playerOne.setName(name);
	cout << "What would you like to be your symbol?" << endl;
	cin >> symbol;
	cin.ignore();
	playerOne.setSymbol(symbol);
	cout << "Okay, you are " << playerOne.getName() << " using " << playerOne.getSymbol() << endl;
	cout << endl;


	cout << "Now Player 2" << endl;
	cout << "What is your name?" << endl;
	cin >> name;
	while (name == playerOne.getName()) {
		cout << "You can't have the same name silly, try again" << endl;
		cin >> name;
	}
	playerTwo.setName(name);
	cout << "What would you like to be your symbol?" << endl;
	cin >> symbol;
	cin.ignore();
	while (symbol == playerOne.getSymbol()) {
		cout << "Haven't you learned? Try again" << endl;
		cin >> symbol;
	}
	playerTwo.setSymbol(symbol);
	cout << "Okay, you are " << playerTwo.getName() << " using " << playerTwo.getSymbol() << endl;
}









//Begins the game
bool enterGame(char gameBoard[][BOARD_SIZE], Player& playerOne, Player& playerTwo) {
	bool gameWon = 0;
	int turnsTaken = 0;

	while (!gameWon) {
		printBoard(gameBoard);

		//Takes playerOne's turn if the game hasn't been won. If playerOne wins, the game ends.
		if (!gameWon) {
			gameWon = playersTurn(gameBoard, playerOne);
			turnsTaken++;
		}

		if (gameWon) {
			playerOne.setWin();
			cout << "\nCongratulations " << playerOne.getName() << ", you won!" << endl;
			return true;
		}

		if (turnsTaken == 9) {
			cout << "\nTie!" << endl;
			return false;
		}

		printBoard(gameBoard);

		//Takes playerTwos turn if the game hasn't been won. If playerTwo wins, the game ends.
		if (!gameWon) {
			gameWon = playersTurn(gameBoard, playerTwo);
			turnsTaken++;
		}

		if (gameWon) {
			playerTwo.setWin();
			cout << "\nCongratulations " << playerTwo.getName() << ", you won!" << endl;
			return true;
		}
	}
}








//Creates a brand new board
void createBoard(char gameBoard[][BOARD_SIZE]) {
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++) {
			gameBoard[i][x] = '_';
		}
	}
}








//Prints the current board
void printBoard(char gameBoard[][BOARD_SIZE]) {
	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int x = 0; x < 3; x++) {
			cout << gameBoard[i][x] << " ";
		}
	}
	cout << endl;
}








//Welcome message
void promptMessage() {
	cout << "Hello! You are playing Tic Tac Toe, created by yours truly, Dylan Pierre" << endl;
	cout << "Rules are simple, get three symbols in a straight line, or diagnolly to win" << endl;
	cout << "You will be prompted to enter a row, then a column, to place your symbol";
	for (int x = 0; x < 3; x++) {
		cout << endl;
		for (int x = 0; x < 3; x++) {
			cout << "_ ";
		}
	}
	cout << "\n\nThis is the board." << endl;
	cout << "This is you: '3 3'" << endl;
	for (int x = 0; x < 2; x++) {
		cout << endl;
		for (int x = 0; x < 3; x++) {
			cout << "_ ";
		}
	}
	cout << endl;
	cout << "_ _ x" << endl;
	cout << "See how that worked? Simple!" << endl;
}








//Checks the board to see if there is a winner
bool testBoard(char gameBoard[][BOARD_SIZE], Player& testPlayer) {

		//Check Rows and Cols
		for (int x = 0; x < 3; x++) {
			int y = 0;
			if (gameBoard[x][y] == testPlayer.getSymbol() &&
				gameBoard[x][y+1] == testPlayer.getSymbol() &&
				gameBoard[x][y+2] == testPlayer.getSymbol())
				return true;
		}

		for (int y = 0; y < 3; y++) {
			int x = 0;
			if (gameBoard[x][y] == testPlayer.getSymbol() &&
				gameBoard[x+1][y] == testPlayer.getSymbol() &&
				gameBoard[x+2][y] == testPlayer.getSymbol())
				return true;
		}

		//Check Diagnolly
		if (gameBoard[0][0] == testPlayer.getSymbol() &&
			gameBoard[1][1] == testPlayer.getSymbol() &&
			gameBoard[2][2] == testPlayer.getSymbol())
			return true;

		if (gameBoard[0][2] == testPlayer.getSymbol() &&
			gameBoard[1][1] == testPlayer.getSymbol() &&
			gameBoard[2][0] == testPlayer.getSymbol())
			return true;

	return false;
}






bool playersTurn(char gameBoard[BOARD_SIZE][BOARD_SIZE], Player& testPlayer) {
	int row = 0, col = 0;
		cout << testPlayer.getName() << "'s turn" << endl;
		cin >> row >> col;
		while (row > 3 || col > 3) {
			cout << "Please choose between 1-3." << endl;
			cin >> row >> col;
		}
		while (gameBoard[row - 1][col - 1] != '_') {
			cout << "This space is occupied. Try again" << endl;
			cin >> row >> col;
		}
		gameBoard[row - 1][col - 1] = testPlayer.getSymbol();

		if (testBoard(gameBoard, testPlayer)) {
			return true;
		}

		else return false;
}