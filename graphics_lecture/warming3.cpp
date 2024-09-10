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
	void print_point();
	void far_distance();
	void close_distance();
	void print_sort_up();
	void print_sort_down();
	void print_for_debug() {
		std::cout << "저장된 리스트: \n";
		for (int line = 19; line > -1; --line) {
			std::println("{:02d} | ({},{},{})\n", line, list[line].x, list[line].y, list[line].z);
		}
	}
};

void point_list::f_input_point(int x, int y, int z) {
	if (list[19].filled) {
		list[19].x = x;
		list[19].y = y;
		list[19].z = z;
		list[19].filled = true;
	}
	else {
		int i=18;
		while (list[i].filled) {
			--i;
			if (i == 0 && list[i].filled) {
				std::cout << "리스트가 가득 차 있습니다";
				return;
			}
		}
		for(int cur = i; cur < 19; cur++) {
			list[cur] = list[cur + 1];
		}
		list[19].x = x;
		list[19].y = y;
		list[19].z = z;
		list[19].filled = true;
	}
	
}
void point_list::f_del_point() {

}
void point_list::e_input_point(int x, int y, int z) {

}
void point_list::e_del_point() {

}
void point_list::print_point() {

}
void point_list::far_distance() {

}
void point_list::close_distance() {

}
void point_list::print_sort_up() {

}
void point_list::print_sort_down() {

}


int main() {
	point_list p;
	p.print_for_debug();
}