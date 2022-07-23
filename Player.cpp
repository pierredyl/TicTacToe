#include "Player.h"



Player::Player() {
	playerName = "boring. Default";
	playerSymbol = 'x';
	winCount = 0;
}




void Player::setName(std::string newName) {
	playerName = newName;
}




void Player::setSymbol(char newSymbol) {
	playerSymbol = newSymbol;
}





std::string Player::getName() {
	return playerName;
}





char Player::getSymbol() {
	return playerSymbol;
}




void Player::setWin() {
	winCount++;
}




int Player::getWinCount() {
	return winCount;
}
