#include<iostream>
#include<Windows.h>
#include<random>
#include<conio.h>
#include<print>
#include<stack>
#define way_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
#define obs_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
#define player_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
#define default_color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

char board[30][30]{};
int player_x{};
int player_y{};
int dir[4][2] = {
	{-1, 0}, //╩С
	{1, 0 }, //го
	{0, -1}, //аб
	{0, 1 } //©Л
};


class player {
private:
	int player_x;
	int player_y;

public:
	player() {
		player_x = 0;
		player_y = 0;
	}

	void go_w() {
		if (player_y - 1 > -1 && board[player_y - 1][player_x] == '0') {
			board[player_y][player_x] = '0';
			--player_y;
		}
	}
	void go_a() {
		if (player_x - 1 > -1 && board[player_y][player_x - 1] == '0') {
			board[player_y][player_x] = '0';
			--player_x;
		}
	}
	void go_s() {
		if (player_y + 1 < 30 && board[player_y + 1][player_x] == '0') {
			board[player_y][player_x] = '0';
			++player_y;
		}
	}
	void go_d() {
		if (player_x + 1 < 30 && board[player_y][player_x + 1] == '0') {
			board[player_y][player_x] = '0';
			++player_x;
		}
	}
	int get_x() {
		return player_x;
	}
	int get_y() {
		return player_y;
	}
	void init_player() {
		player_x = 0;
		player_y = 0;
	}
};






void gotoxy(int go_x, int go_y) {
	COORD pos = { go_x, go_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print_board();
void init_board();
void make_path();




int main() {
	bool is_player = false;
	player p1;
	while (true) {
		char menu;
		if(_kbhit){
			menu = _getch();
			switch (menu) {
			case 13:
				init_board();
				make_path();
				is_player = false;
				break;

			case 'r':
			if(not is_player){
				p1.init_player();
				board[p1.get_y()][p1.get_x()] = '*';
				is_player = true;
			}

				break;

			case 'w':
				if (is_player) {
					p1.go_w();
					board[p1.get_y()][p1.get_x()] = '*';
				}

				break;

			case 'a':
				if (is_player) {
					p1.go_a();
					board[p1.get_y()][p1.get_x()] = '*';
				}
	
				break;


			case 's':
				if (is_player) {
					p1.go_s();
					board[p1.get_y()][p1.get_x()] = '*';
				}
	
				break;


			case 'd':
				if (is_player) {
					p1.go_d();
					board[p1.get_y()][p1.get_x()] = '*';
				}

				break;


			case 'q':

				return 0;
			
			default:

				break;
			}
		}
		print_board();
	}
	
	
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
}

void make_path() {
	int cur_x = 0, cur_y = 0;
	int step_now_dir = 0;
	int direction, dx, dy;

	std::stack<std::pair<int, int>> path_stack;
	path_stack.push({ cur_x, cur_y });

	srand((unsigned)time(0));
	board[cur_y][cur_x] = '0';

	while (cur_x < 29 || cur_y < 29) {
		bool move = false;

		for (int temp = 0; temp < 4; ++temp) {
			direction = rand() % 4;
			dy = dir[direction][0];
			dx = dir[direction][1];

			if (cur_y + dy >= 0 && cur_y + dy < 30 && cur_x + dx >= 0 && cur_x + dx < 30 &&
				board[cur_y + dy][cur_x + dx] == '0') {
				continue; 
			}
			if ((direction == 0 || direction == 2) && step_now_dir > 2) {
				continue;
			}
			else if ((direction == 1 || direction == 3) && step_now_dir > 3) {
				continue;
			}
			if (cur_y + dy >= 0 && cur_y + dy < 30 && cur_x + dx >= 0 && cur_x + dx < 30 &&
				board[cur_y + dy][cur_x + dx] != 'X') {
				cur_x += dx;
				cur_y += dy;
				board[cur_y][cur_x] = '0';  
				step_now_dir++;
				path_stack.push({ cur_x, cur_y });  

			
				if ((direction == 0 || direction == 2) && step_now_dir >= 3) {
					step_now_dir = 0;
				}
				else if ((direction == 1 || direction == 3) && step_now_dir >= 4) {
					step_now_dir = 0;
				}

				move = true;  
				break;
			}
		}

	
		if (!move) {
			if (!path_stack.empty()) {
				std::pair<int, int> prev_position = path_stack.top();
				path_stack.pop();
				cur_x = prev_position.first;
				cur_y = prev_position.second;
			}
			else {
				break; 
			}
		}

		print_board();
	}

	


}


