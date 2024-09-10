#include<iostream>

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
	void f_del_point(int x, int y, int z);
	void e_input_point(int x, int y, int z);
	void e_del_point(int x, int y, int z);
	void print_point();
	void far_distance();
	void close_distance();
	void print_sort_up();
	void print_sort_down();

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
		}
		for(int cur = i; i < 19; i++) {
			list[i].x
		}
	}
}
void point_list::f_del_point(int x, int y, int z) {

}
void point_list::e_input_point(int x, int y, int z) {

}
void point_list::e_del_point(int x, int y, int z) {

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