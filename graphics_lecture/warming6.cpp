#include<iostream>
#include<Windows.h>
#include<random>
#include<conio.h>
#include<print>
#define way_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
#define obs_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
#define player_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
#define default_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

char board[30][30]{};
int player_x{};
int player_y{};
int dir[4][2] = {
	(-1, 0), //╩С
	(1, 0), //го
	(0, -1), //аб
	(0, 1) //©Л
};



void gotoxy(int go_x, int go_y) {
	COORD pos = { go_x, go_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print_board();
void init_board();
void make_path();




int main() {
	init_board();
	make_path();
	print_board();
	
}



void print_board() {
	gotoxy(0, 0);
	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < 30; ++x) {
			switch (board[y][x]) {
			case '1':
				default_color;
				std::print(" {} ", board[y][x]);
				break;

			case '0':
				way_color;
				std::print(" {} ", board[y][x]);
				break;

			case 'X':
				obs_color;
				std::print(" {} ", board[y][x]);
				break;

			case '*':
				player_color;
				std::print(" {} ", board[y][x]);
				break;

			default:

				break;

			}
		}
		std::cout << '\n';
	}
	default_color;
}

void init_board() {
	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < 30; ++x) {
			board[y][x] = '1';
		}
	}
	
	srand((unsigned)time(0));
	for (int i = 0; i < 30; ++i) {
		int ox = rand() % 30;
		int oy = rand() % 30;
		if (board[oy][ox] == 'X') {
			--i;
		}
		else if ((ox == 29 && oy == 29)||(ox==0&&oy==0)) {
			--i;
			board[oy][ox] = '0';
		}
		else {
			board[oy][ox] = 'X';
		}
	}
	board[0][0] = '0';
	board[29][29] = '0';
}


void make_path() {
	
}