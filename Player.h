#include <iostream>
#include <string>

class Player {
	private:
		std::string playerName;
		char playerSymbol;
		int winCount;


	public:
		Player();
		void setName(std::string newName);
		void setSymbol(char newSymbol);
		std::string getName();
		char getSymbol();
		void setWin();
		int getWinCount();
};
