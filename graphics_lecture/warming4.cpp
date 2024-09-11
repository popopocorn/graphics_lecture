#include<iostream>
#include<random>
typedef struct board {
	int what_card;
	bool is_reverse;
};
class card_check {
private:
	board chek_board[5][5]{};
	int score{};

public:
	void print_board();
	void select_board(int x, int y);
};