#include<iostream>
#include<stdlib.h>
#include<random>
#define b_reset while(getchar()!='\n');

class procession {
private:
	int result_pro[4][4] = {};
	int element[4][4] = {};
	int element2[4][4] = {};
	int have_two[2] = {};
	int is_silhang = 0;
public:
	procession() {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 1);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				element[i][j] = dis(gen);
				element2[i][j] = dis(gen);
			}
		}
		std::random_device two;
		std::mt19937 gen_two(two());
		std::uniform_int_distribution<int> sec(1, 16);
		have_two[0] = sec(gen_two);
		while (1) {
			have_two[1] = sec(gen_two);
			if (have_two[0] != have_two[1]) {
				break;
			}
		}
		int count = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				count++;
				if (count == have_two[0] || count == have_two[1]) {
					element[i][j] = 2;
				}
			}
		}
		have_two[0] = sec(gen_two);
		while (1) {
			have_two[1] = sec(gen_two);
			if (have_two[0] != have_two[1]) {
				break;
			}
		}
		count = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				count++;
				if (count == have_two[0] || count == have_two[1]) {
					element2[i][j] = 2;
				}
			}
		}


	}
	void mult_pro();
	void plus_pro();
	void minus_pro();
	void det_pro();
	void trans_pro();
	void holzzag_pro();
	void reset_pro();
	void mult_num(int num);
	void show_result();
	void show_pro();


};
void procession::mult_pro() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int a = 0; a < 4; a++) {
				result_pro[i][j] += element[i][a] * element2[a][j];
			}
		}
	}
}
void procession::plus_pro() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result_pro[i][j] = element[i][j] + element2[i][j];
		}
	}
}
void procession::minus_pro() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result_pro[i][j] = element[i][j] - element2[i][j];
		}
	}
}
void procession::det_pro() {

}
void procession::trans_pro() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result_pro[i][j] = element[j][i];
		}
	}
	show_result();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result_pro[i][j] = element2[j][i];
		}
	}
	show_result();
}
void procession::holzzag_pro() {
	if (is_silhang==0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (element[i][j] % 2 == 0) {
					result_pro[i][j] = 0;
				}
				else {
					result_pro[i][j] = element[i][j];
				}
			}
		}
		is_silhang = 1;
	}
	else if(is_silhang==1){
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (element[i][j] % 2 != 0) {
					result_pro[i][j] = 0;
				}
				else {
					result_pro[i][j] = element[i][j];
				}
			}
		}
		is_silhang = 2;
	}
	else {
		show_pro();
	}
	
}
void procession::reset_pro() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			element[i][j] = dis(gen);
			element2[i][j] = dis(gen);
		}
	}
	std::random_device two;
	std::mt19937 gen_two(two());
	std::uniform_int_distribution<int> sec(0, 16);
	have_two[0] = sec(gen_two);
	while (1) {
		have_two[1] = sec(gen_two);
		if (have_two[0] != have_two[1]) {
			break;
		}
	}
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			count++;
			if (count == have_two[0] || count == have_two[1]) {
				element[i][j] = 2;
			}
		}
	}
	have_two[0] = sec(gen_two);
	while (1) {
		have_two[1] = sec(gen_two);
		if (have_two[0] != have_two[1]) {
			break;
		}
	}
	count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			count++;
			if (count == have_two[0] || count == have_two[1]) {
				element2[i][j] = 2;
			}
		}
	}
}
void procession::mult_num(int num) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result_pro[i][j] = element[i][j] * num;
		}
	}
}
void procession::show_result() {
	std::cout << "결과 행렬:\n";
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			std::cout << result_pro[y][x] << " ";
		}
		std::cout << "\n";
	}
}

void procession::show_pro() {
	std::cout << "생성된 행렬1:\n";
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			std::cout << element[y][x] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n생성된 행렬2:\n";
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			std::cout << element2[y][x] << " ";
		}
		std::cout << "\n";
	}
}


int main() {
	char menu;
	procession proce;
	proce.show_pro();
	while (1) {

		std::cout << "사용할 명령 입력:";
		std::cin >> menu;
		b_reset;
		switch (menu) {

		case 'm':
			proce.mult_pro();
			proce.show_result();
			break;

		case 'a':
			proce.plus_pro();
			proce.show_result();
			break;

		case 'd':
			proce.minus_pro();
			proce.show_result();
			break;
		case 'r':

			break;
		case 't':
			proce.trans_pro();
			proce.show_result();
			break;
		case 'e':
			proce.holzzag_pro();
			proce.show_result();
			break;
		case 's':
			proce.reset_pro();
			proce.show_pro();
			break;
		case 'q':

			return 0;

		case 'n':

			break;
		default:
			break;
		}
	}

}