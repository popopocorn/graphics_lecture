#include<iostream>
#include<random>
#include<Windows.h>
#include<string>
#include<random>
void gotoxy(int go_x, int go_y) {
	COORD pos = { go_x, go_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


typedef struct board {
	char what_card;
	bool is_reverse;
};
class card_check {
private:
	board check_board[5][5]{};
	int score{};
	int card_count{ 25 };
	std::string cards = {"AABBCCDDEEFFGGHHIIJJKKLL@"};
	int card1_x;
	int card1_y;
	int card2_x;
	int card2_y;

public:
	card_check() {
		
		
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				check_board[y][x].what_card = 0;
				check_board[y][x].is_reverse = false;
			}
		}
	}
	void print_board();
	void select_board();
	void check_card();
	void change_coord(std::string card1, std::string card2);
	void calc_score();
};

void card_check::print_board() {
	gotoxy(0, 0);
	std::cout << "  a  b  c  d  e\n";
	for (int y = 0; y < 5; ++y) {
		std::cout << y + 1;
		for (int x = 0; x < 5; ++x) {
			if(!check_board[y][x].is_reverse) {
				std::cout << " * ";
			}
			else {
				std::cout << check_board[y][x].what_card;
			}
		}
		std::cout << '\n';
	}
	gotoxy(0, 7);
	std::cout << "현재 점수: " << score;
}
void card_check::select_board() {
	std::string card1{};
	std::string card2{};
	gotoxy(0, 9);
	std::cout << "                                                       ";
	gotoxy(0, 9);
	std::cout << "뒤집을 두 카em의 좌표를 입력하시오: ";
	std::cin >> card1 >> card2;
	while (getchar() != '\n');
	Sleep(1000);
	change_coord(card1, card2);
}

void card_check::change_coord(std::string card1, std::string card2) {
	switch(card1[0]) {
	case 'a':
		card1_x = 0;
		break;

	case 'b':
		card1_x = 1;
		break;

	case 'c':
		card1_x = 2;
		break;

	case 'd':
		card1_x = 3;
		break;

	case 'e':
		card1_x = 4;
		break;
	
	
	}
	card1_y = int(card1[1]);

	switch (card2[0]) {
	case 'a':
		card2_x = 0;
		break;

	case 'b':
		card2_x = 1;
		break;

	case 'c':
		card2_x = 2;
		break;

	case 'd':
		card2_x = 3;
		break;

	case 'e':
		card2_x = 4;
		break;


	}
	card2_y = int(card2[1]);
}
void card_check::check_card() {

}

void card_check::calc_score() {

}

int main() {
	card_check deck;

	while(true){
		deck.print_board();
		deck.select_board();
	}
}