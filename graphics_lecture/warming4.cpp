#include<iostream>
#include<random>
#include<Windows.h>
#include<string>
#include<algorithm>
#include<print>
#include<time.h>
#include<conio.h>

#define card_a  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
#define card_b  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
#define card_c  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
#define card_d  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
#define card_e  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
#define card_f  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
#define card_g  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#define card_h  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
#define card_i  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
#define card_j  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
#define card_k  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
#define card_l  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
#define default_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);






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
	std::string cards = {"AABBCCDDEEFFGGHHIIJJKKLL@"};
	int card1_x;
	int card1_y;
	int card2_x;
	int card2_y;
	

public:
	card_check() {
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(cards.begin(), cards.end(), g);
		int temp_count = 0;
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				check_board[y][x].what_card = cards[temp_count];
				check_board[y][x].is_reverse = true;
				++temp_count;
			}
		}
	}
	void print_board();
	void select_board();
	void check_card();
	void change_coord(std::string card1);
	void calc_score();
	
	int get_score() {
		return score;
	}
	void reset_game() {
		score = 0;
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(cards.begin(), cards.end(), g);
		int temp_count = 0;
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				check_board[y][x].what_card = cards[temp_count];
				check_board[y][x].is_reverse = true;
				++temp_count;
			}
		}
	}
};

void card_check::print_board() {
	gotoxy(0, 0);
	std::cout << "  a  b  c  d  e\n";
	for (int y = 0; y < 5; ++y) {
		default_color;
		std::cout << y + 1;
		for (int x = 0; x < 5; ++x) {
			
			if(!check_board[y][x].is_reverse) {
				default_color;
				std::cout << " * ";
			}
			else {
				switch (check_board[y][x].what_card) {
				case 'A':
					card_a;
					break;

				case 'B':
					card_b;
					break;

				case 'C':
					card_c;
					break;

				case 'D':
					card_d;
					break;

				case 'E':
					card_e;
					break;

				case 'F':
					card_f;
					break;

				case 'G':
					card_g;
					break;

				case 'H':
					card_h;
					break;

				case 'I':
					card_i;
					break;

				case 'J':
					card_j;
					break;

				case 'K':
					card_k;
					break;

				case 'L':
					card_l;
					break;

				case '@':
					default_color;
					break;

				default:

					break;
				}
				std::print(" {} ",check_board[y][x].what_card);
			}

		}
		std::cout << '\n';
	}
	gotoxy(0, 7);
	default_color;
	std::cout << "현재 점수: " << score;
}
void card_check::select_board() {
	std::string card1{};
	gotoxy(0, 9);
	std::cout << "                                                       ";
	gotoxy(0, 9);
	std::cout << "뒤집을 두 카드의 좌표를 입력하시오: ";
	std::cin >> card1;
	while (getchar() != '\n');
	Sleep(1000);

	change_coord(card1);
	if (check_board[card1_y][card1_x].is_reverse || check_board[card2_y][card2_x].is_reverse) {
		gotoxy(0, 11);
		std::cout << "이미 뒤집힌 카드 입니다.";
	}
	else {
		if (not check_board[card1_y][card1_x].is_reverse) {
			check_board[card1_y][card1_x].is_reverse = true;
		}
		if (not check_board[card2_y][card2_x].is_reverse) {
			check_board[card2_y][card2_x].is_reverse = true;
		}
	}
}

void card_check::change_coord(std::string card1) {
	if (card1[0] == 'r' || card1[0] == 'R') {
		reset_game();
		return;
	}
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
	
	default:
		gotoxy(0, 11);
		std::cout << "올바르지 않은 위치입니다.\n";
		return;
	}
	

	switch (card1[3]) {
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

	default:
		gotoxy(0, 11);
		std::cout << "올바르지 않은 위치입니다.\n";
		return;
	}
	if (int(card1[1]) - '1' < 5 && int(card1[4]) - '1' < 5) {
		card1_y = int(card1[1]) - '1';
		card2_y = int(card1[4]) - '1';
	}

}
void card_check::check_card() {
	if (check_board[card1_y][card1_x].what_card == check_board[card2_y][card2_x].what_card) {
		score += 2;
	}
	else if (check_board[card1_y][card1_x].what_card == '@' || check_board[card2_y][card2_x].what_card == '@') {
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {
				if ((y == card1_y && x == card1_x) || (y == card2_y && x == card2_x)) {
					continue;
				}
				else if(check_board[card1_y][card1_x].what_card == check_board[y][x].what_card || check_board[card2_y][card2_x].what_card == check_board[y][x].what_card) {
					check_board[y][x].is_reverse = true;
					gotoxy(0, 11);
					std::cout << "조커발견!";
					score += 2;
					return;
				}
			}
		}
	}else {
		gotoxy(0, 10);
		std::cout << "카드가 일치하지 않습니다";
		check_board[card1_y][card1_x].is_reverse = false;
		check_board[card2_y][card2_x].is_reverse = false;
	}
}

void card_check::calc_score() {

}

int main() {
	time_t start, end;
	card_check deck;
	start = time(NULL);
	while(true){
		deck.print_board();
		deck.select_board();
		deck.print_board();
		Sleep(1000);
		deck.check_card();
		if (deck.get_score() > 23) {
			end = time(NULL);
			gotoxy(0, 12);
			std::print("소요시간 {}초", end-start);
			return 0;
		}
	}
}