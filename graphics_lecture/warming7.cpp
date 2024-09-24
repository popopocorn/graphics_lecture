#include<iostream>
#include<Windows.h>
#define contact_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
#define default_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


class move_board {
private:
	int board[30][30][2]{};
	int	width{ 0 };
	int height{ 0 };

public:
	void print_board() {
		gotoxy(0, 0);
		for (int y = 0; y < 30; ++y) {
			for (int x = 0; x < 30; ++x) {
				if (board[y][x][0] == 1) {
					if (board[y][x][1] == 1) {
						contact_color;
						std::cout << " # ";
					}else{
						default_color;
						std::cout << " 0 ";
					}
				}
				else if (board[y][x][1] == 1) {
					default_color;
					std::cout << " X ";
				}
				else {
					default_color;
					std::cout << " . ";
				}
			}
			std::cout << '\n';
		}
		default_color;
	}
	void set_square();
	void move_horizon(char command);
	void move_vertical(char command);
	void change_size(char command);
	void reset();


};

void move_board::set_square() {
	int startx;
	int starty;
	int endx;
	int endy;
	std::cout << "좌표를 입력하시오: ";
	std::cin >> startx >> starty >> endx >> endy;
	while (getchar() != '\n');
	height = endy - starty + 1;
	width = endx - startx + 1;
	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < 30; ++x) {
			if (x >= startx && x <= endx && y >= starty && y <= endy) {

				board[y][x][0] = 1;

			}
		}
	}
	std::cout << "좌표를 입력하시오: ";
	std::cin >> startx >> starty >> endx >> endy;
	while (getchar() != '\n');
	height = endy - starty + 1;
	width = endx - startx + 1;
	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < 30; ++x) {
			if (x >= startx && x <= endx && y >= starty && y <= endy) {

				board[y][x][1] = 1;

			}
		}
	}

}


void move_board::move_horizon(char command) {
	// 우측 이동
	if (command == 'x') {

		for (int y = 0; y < 30; ++y) {
			int last_val = board[y][29][0];
			for (int x = 28; x >= 0; --x) {
				board[y][x + 1][0] = board[y][x][0];
			}
			board[y][0][0] = last_val;
		}
	}
	// 좌측 이동
	else if(command=='X') {

		for (int y = 0; y < 30; ++y) {
			int first_val = board[y][0][0];
			for (int x = 1; x < 30; ++x) {
				board[y][x - 1][0] = board[y][x][0];
			}
			board[y][29][0] = first_val;
		}
	}
	else if (command == 'w') {
		for (int y = 0; y < 30; ++y) {
			int last_val = board[y][29][1];
			for (int x = 28; x >= 0; --x) {
				board[y][x + 1][1] = board[y][x][1];
			}
			board[y][0][1] = last_val;
		}
	}
	else {
		for (int y = 0; y < 30; ++y) {
			int first_val = board[y][0][1];
			for (int x = 1; x < 30; ++x) {
				board[y][x - 1][1] = board[y][x][1];
			}
			board[y][29][1] = first_val;
		}
	}
}


void move_board::move_vertical(char command) {
	if (command == 'y') {

		for (int x = 0; x < 30; ++x) {
			int last_val = board[29][x][0];
			for (int y = 28; y >= 0; --y) {
				board[y + 1][x][0] = board[y][x][0];
			}
			board[0][x][0] = last_val;
		}
	}
	// 좌측 이동
	else if(command=='Y') {

		for (int x = 0; x < 30; ++x) {
			int first_val = board[0][x][0];
			for (int y = 1; y < 30; ++y) {
				board[y - 1][x][0] = board[y][x][0];
			}
			board[29][x][0] = first_val;
		}
	}
	else if (command == 'a') {
		for (int x = 0; x < 30; ++x) {
			int last_val = board[29][x][1];
			for (int y = 28; y >= 0; --y) {
				board[y + 1][x][1] = board[y][x][1];
			}
			board[0][x][1] = last_val;
		}
	}
	else {
		for (int x = 0; x < 30; ++x) {
			int first_val = board[0][x][1];
			for (int y = 1; y < 30; ++y) {
				board[y - 1][x][1] = board[y][x][1];
			}
			board[29][x][1] = first_val;
		}
	}

}
void move_board::change_size(char command) {
	bool up_flag = false;
	bool down_flag = false;
	if (command == 's') {
		for (int y = 0; y < 30; ++y) {
			for (int x = 29; x > -1; --x) {
				if (x != 29 && board[y][x][0] == 1 && board[y][x + 1][0] == 0) {
					board[y][x + 1][0] = 1;
					up_flag = true;
				}
			}
		}
		if (up_flag) {
			++width;
			up_flag = false;
		}
		for (int x = 0; x < 30; ++x) {
			for (int y = 29; y > -1; --y) {
				if (y != 29 && board[y][x][0] == 1 && board[y + 1][x][0] == 0) {
					board[y + 1][x][0] = 1;
				}

			}
		}
		if (up_flag) {
			++height;
			up_flag = false;
		}


	}
	else if(command=='S') {

		for (int y = 0; y < 30; ++y) {
			for (int x = 0; x < 30; ++x) {
				if (x != 29 && board[y][x][0] == 1 && board[y][x + 1][0] == 0) {
					board[y][x][0] = 0;
					down_flag = true;
				}

			}
			if (board[y][29][0] == 1 && board[y][0][0] == 0) {
				board[y][29][0] = 0;
				down_flag = true;
			}
		}
		if (down_flag) {
			--width;
			down_flag = false;
		}
		for (int x = 0; x < 30; ++x) {
			for (int y = 0; y < 30; ++y) {
				if (y != 29 && board[y][x][0] == 1 && board[y + 1][x][0] == 0) {
					board[y][x][0] = 0;
					down_flag = true;
				}
			}
			if (board[29][x][0] == 1 && board[0][x][0] == 0 ) {
				board[29][x][0] = 0;
				down_flag = true;
			}
		}
		if (down_flag) {
			--height;
			down_flag = false;
		}
	}
	else if (command == 'd') {
		for (int y = 0; y < 30; ++y) {
			for (int x = 29; x > -1; --x) {
				if (x != 29 && board[y][x][1] == 1 && board[y][x + 1][1] == 0) {
					board[y][x + 1][1] = 1;
					up_flag = true;
				}
			}
		}
		if (up_flag) {
			++width;
			up_flag = false;
		}
		for (int x = 0; x < 30; ++x) {
			for (int y = 29; y > -1; --y) {
				if (y != 29 && board[y][x][1] == 1 && board[y + 1][x][1] == 0) {
					board[y + 1][x][1] = 1;
				}

			}
		}
		if (up_flag) {
			++height;
			up_flag = false;
		}
	}
	else {
		for (int y = 0; y < 30; ++y) {
			for (int x = 0; x < 30; ++x) {
				if (x != 29 && board[y][x][1] == 1 && board[y][x + 1][1] == 0) {
					board[y][x][1] = 0;
					down_flag = true;
				}

			}
			if (board[y][29][1] == 1 && board[y][0][1] == 0) {
				board[y][29][1] = 0;
				down_flag = true;
			}
		}
		if (down_flag) {
			--width;
			down_flag = false;
		}
		for (int x = 0; x < 30; ++x) {
			for (int y = 0; y < 30; ++y) {
				if (y != 29 && board[y][x][1] == 1 && board[y + 1][x][1] == 0) {
					board[y][x][1] = 0;
					down_flag = true;
				}
			}
			if (board[29][x][1] == 1 && board[0][x][1] == 0) {
				board[29][x][1] = 0;
				down_flag = true;
			}
		}
		if (down_flag) {
			--height;
			down_flag = false;
		}
	}
}


void move_board::reset() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			board[i][j][0] = 0;
		}
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			board[i][j][1] = 0;
		}
	}

	int startx;
	int starty;
	int endx;
	int endy;
	gotoxy(0, 31);
	std::cout << "                                                             ";
	gotoxy(0, 31);
	std::cout << "좌표를 입력하시오: ";
	std::cin >> startx >> starty >> endx >> endy;
	while (getchar() != '\n');
	height = endy - starty + 1;
	width = endx - startx + 1;
	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < 30; ++x) {
			if (x >= startx && x <= endx && y >= starty && y <= endy) {

				board[y][x][0] = 1;

			}
		}
	}
	std::cout << "좌표를 입력하시오: ";
	std::cin >> startx >> starty >> endx >> endy;
	while (getchar() != '\n');
	height = endy - starty + 1;
	width = endx - startx + 1;
	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < 30; ++x) {
			if (x >= startx && x <= endx && y >= starty && y <= endy) {

				board[y][x][1] = 1;

			}
		}
	}
}


int main() {
	move_board board;
	char menu{};
	char temp_menu{};
	board.set_square();
	while (true) {
		board.print_board();
		std::cin >> menu;
		while (getchar() != '\n');
		temp_menu = tolower(menu);
		switch (temp_menu) {
		case 'x':
			board.move_horizon(menu);
			break;

		case 'y':
			board.move_vertical(menu);
			break;

		case 's':
			board.change_size(menu);
			break;

		case 'w':
			board.move_horizon(menu);
			break;

		case 'a':
			board.move_vertical(menu);
			break;

		case 'd':
			board.change_size(menu);
			break;

		case 'r':
			board.reset();
			break;

		case 'q':

			return 0;


		}
	}

}