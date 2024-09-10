#include<iostream>
#include<print>

typedef struct tuple {
	int x;
	int y;
	int z;
	bool filled = false;
};

class point_list {
private:
	tuple list[20]{};

public:
	
	void f_input_point(int x, int y, int z);
	void f_del_point();
	void e_input_point(int x, int y, int z);
	void e_del_point();
	void num_of_point();
	void clean_list();
	void far_distance();
	void close_distance();
	void print_sort_up();
	void print_sort_down();
	void print_for_debug() {
		std::cout << "저장된 리스트: \n";
		for (int line = 19; line > -1; --line) {
			if(list[line].filled) {
				std::println("{:02d} | ({},{},{})\n", line, list[line].x, list[line].y, list[line].z);
			}
			else {
				std::println("{:02d} | ()\n", line);
			}
		}
	}
};

void point_list::f_input_point(int x, int y, int z) {
	if (!list[19].filled) {
		list[19].x = x;
		list[19].y = y;
		list[19].z = z;
		list[19].filled = true;
	}
	else {
		int empty_index = 19;
		while (list[empty_index].filled) {
			if (empty_index == 0) {
				break;
			}
			--empty_index;
			
		}


		for(int cur = empty_index; cur < 19; ++cur) {
			list[cur] = list[cur+1];
		}
		list[19].x = x;
		list[19].y = y;
		list[19].z = z;
		list[19].filled = true;
	}
	
}
void point_list::f_del_point() {
	if (!list[19].filled) {
		std::cout << "해당 칸에는 점이 없습니다.\n";
		return;
	}
	list[19].filled = false;
	

}
void point_list::e_input_point(int x, int y, int z) {
	if (!list[0].filled) {
		list[0].x = x;
		list[0].y = y;
		list[0].z = z;
		list[0].filled = true;
	}
	else {
		int empty_index = 0;
		while (list[empty_index].filled) {
			if (empty_index == 19) {
				break;
			}
			++empty_index;

		}


		for (int cur = empty_index; cur >-1; --cur) {
			list[cur+1] = list[cur];
		}
		list[0].x = x;
		list[0].y = y;
		list[0].z = z;
		list[0].filled = true;
	}
}
void point_list::e_del_point() {
	if (!list[0].filled) {
		std::cout << "해당 칸에는 점이 없습니다.\n";
		return;
	}
	list[0].filled = false;

}
void point_list::num_of_point() {
	int count{};
	for (int y = 0; y < 20; ++y) {
		if (list[y].filled) {
			++count;
		}
	}

	std::println("리스트 내의 점 개수: {}개", count);
}

void point_list::clean_list() {
	int x, y, z;
	for (int line = 0; line < 20; ++line) {
		list[line].filled = false;
	}
	std::cout << "점을 입력하시오: ";
	std::cin >> x >> y >> z;
	while (getchar() != '\n');
	e_input_point(x, y, z);
}

void point_list::far_distance() {
	int temp_distance;
	int long_distance{};
	for (int y = 0; y < 20; ++y) {
		temp_distance = pow(list[y].x, 2) + pow(list[y].y, 2) + pow(list[y].z, 2);
		if (temp_distance > long_distance) {
			long_distance = temp_distance;
		}
	}
	for (int line = 0; line < 20; ++line) {
		temp_distance = pow(list[line].x, 2) + pow(list[line].y, 2) + pow(list[line].z, 2);
		if (temp_distance == long_distance) {
			std::println("({}, {}, {})\n", list[line].x, list[line].y, list[line].z);
		}
	}
}
void point_list::close_distance() {
	int temp_distance;
	int short_distance;
	for (int y = 0; y < 20; ++y) {
		if (list[y].filled) {
			short_distance = pow(list[y].x, 2) + pow(list[y].y, 2) + pow(list[y].z, 2);
		}
	}
	for (int y = 0; y < 20; ++y) {
		if (list[y].filled) {
			temp_distance = pow(list[y].x, 2) + pow(list[y].y, 2) + pow(list[y].z, 2);
			if (temp_distance < short_distance) {
				short_distance = temp_distance;
			}
		}
	}
	for (int line = 0; line < 20; ++line) {
		if (list[line].filled) {
			temp_distance = pow(list[line].x, 2) + pow(list[line].y, 2) + pow(list[line].z, 2);
			if (temp_distance == short_distance) {
				std::println("({}, {}, {})\n", list[line].x, list[line].y, list[line].z);
			}
		}
	}
}
void point_list::print_sort_up() {

}
void point_list::print_sort_down() {

}


int main() {
	point_list p;
	char menu{};
	int x,y,z;
	while(true){
		std::cout << "명령을 입력하시오: ";
		std::cin >> menu;
		while (getchar() != '\n');
		switch (menu) {
		case'+':
			std::cout << "좌표를 입력하시오: ";
			std::cin >> x >> y >> z;
			while (getchar() != '\n');
			p.f_input_point(x, y, z);
			break;

		case'-':
			p.f_del_point();
			break;

		case'e':
			std::cout << "좌표를 입력하시오: ";
			std::cin >> x >> y >> z;
			while (getchar() != '\n');
			p.e_input_point(x, y, z);
			break;

		case'd':
			p.e_del_point();
			break;

		case'l':
			p.num_of_point();
			break;

		case'c':
			p.clean_list();
			break;

		case'm':
			p.far_distance();
			break;

		case'n':
			p.close_distance();
			break;

		case'a':

			break;

		case's':

			break;

		case'q':

			return 0;
		case'*':
			p.print_for_debug();
			break;
		}
	}

}