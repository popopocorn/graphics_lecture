#include<iostream>
#include<Windows.h>


void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


class move_board {
private:
	int board[30][30]{};
	int	width{};
	int height{};

public:
	void print_board() {
		system("cls");
		for (int y = 0; y < 30; ++y) {
			for (int x = 0; x < 30; ++x) {
				if (board[y][x] == 1) {
					std::cout << " 0 ";
				}
				else {
					std::cout << " . ";
				}
			}
			std::cout << '\n';
		}
	}
	void set_square();
	void move_horizon(char command);
	void move_vertical(char command);
	void change_size(char command);
	void change_x(char command);
	void change_y(char command);
	void change_xy(char command);
	void clac_area();
	void calc_ratio();
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
	height = endy - starty;
	width = endx - startx;
	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < 30; ++x) {
			if (x >= startx && x <= endx && y >= starty && y <= endy) {

				board[y][x] = 1;

			}
		}
	}

}


void move_board::move_horizon(char command) {
	// 우측 이동
	if (command == 'x') {
	
		for (int y = 0; y < 30; ++y) {
			int last_val = board[y][29];
			for (int x = 28; x >= 0; --x) {
				board[y][x + 1] = board[y][x];
			}
			board[y][0] = last_val;
		}
	}
	// 좌측 이동
	else {
		
		for (int y = 0; y < 30; ++y) {
			int first_val = board[y][0]; 
			for (int x = 1; x < 30; ++x) {
				board[y][x - 1] = board[y][x];
			}
			board[y][29] = first_val; 
		}
	}
}


void move_board::move_vertical(char command) {
	if (command == 'y') {

		for (int x = 0; x < 30; ++x) {
			int last_val = board[29][x];
			for (int y = 28; y >= 0; --y) {
				board[y+1][x] = board[y][x];
			}
			board[0][x] = last_val;
		}
	}
	// 좌측 이동
	else {

		for (int x = 0; x < 30; ++x) {
			int first_val = board[0][x];
			for (int y = 1; y < 30; ++y) {
				board[y-1][x] = board[y][x];
			}
			board[29][x] = first_val;
		}
	}

}
void move_board::change_size(char command) {
	bool up_flag = false;
	if (command == 's') {
		for (int y = 0; y < 30; ++y) {
			for (int x = 29; x > -1; --x) {
				if (x!=29&&board[y][x]==1 && board[y][x+1]==0) {
					board[y][x + 1] = 1;
				}
				else if(x==29 && board[y][x]==1 && board[y][0]!=1) {
					up_flag = true;
				}
			}

			if(up_flag){
				board[y][0] = 1;
			}
			up_flag = false;
		}
		for (int x = 0; x < 30; ++x) {
			for (int y = 29; y > -1; --y) {
				if (y != 29 && board[y][x] == 1 && board[y+1][x] == 0) {
					board[y+1][x] = 1;
				}
				else if (y == 29 && board[y][x] == 1 && board[0][x] != 1) {
					up_flag = true;
				}
			}

			if (up_flag) {
				board[0][x] = 1;
			}
			up_flag = false;
		}
		++height;
		++width;
	}
	else {
		for (int y = 0; y < 30; ++y) {
			for (int x = 0; x < 30; ++x) {
				
			}
		}

	}
}
void move_board::change_x(char command) {

}
void move_board::change_y(char command) {

}
void move_board::change_xy(char command) {

}
void move_board::clac_area() {

}
void move_board::calc_ratio() {

}
void move_board::reset() {

}


int main() {
	move_board board;
	char menu{};
	char temp_menu{};
	board.set_square();
	while(true){
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

		case 'i':
				
			break;

		case 'j':

			break;

		case 'a':

			break;

		case 'm':

			break;

		case 'n':

			break;

		case 'r':

			break;

		case 'q':

			return 0;


		}
	}

}