#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<cctype>
class sentences
{
private:
    std::string sentence[10];
    bool has_color = false;
    bool has_reverse_line = false;
    bool has_insert_at = false;
    bool has_reverse_space = false;
    bool has_change = false;
    bool has_print_sort = false;
public:
    sentences() {
        std::ifstream testFile;
        int i = 0;
        testFile.open("data.txt");
        if (testFile.is_open()) {
            while (i < 10 && std::getline(testFile, sentence[i])) {
                ++i;
            }
        }
        else {
            std::cout << "파일을 찾지 못했습니다\n";
        }
        testFile.close();
    }
    void color();
    void reverse_line();
    void insert_at();
    void reverse_space();
    void change();
    void print();
    void print_sort();
    void find_word();
    void print_4_debug() {
        int i = 0;
        while (true) {
            std::cout << sentence[i] << '\n';
            ++i;
            if (i == 10) {
                break;
            }
        }
    }
};

void sentences::color() {
    if (has_color) {
        int i = 0;
        while (true) {
            std::cout << sentence[i] << '\n';
            ++i;
            if (i == 10) {
                break;
            }
        }
        has_color = !has_color;
    }
    else {





        has_color = !has_color;
    }
}
void sentences::reverse_line() {

}
void sentences::insert_at() {

}
void sentences::reverse_space() {

}
void sentences::change() {

}
void sentences::print() {
  
}

void sentences::print_sort() {

}
void sentences::find_word() {

}

int main() {
    sentences s;
    s.print_4_debug();
    char menu;
    while(true){
        std::cout << "실행할 명령을 입력하시오: ";
        std::cin >> menu;
        switch (menu) {
        case 'c':
            s.color();
            break;

        case 'd':
            break;
        case 'e':
            break;
        case 'f':
            break;
        case 'g':
            break;
        case 'h':
            break;
        case 'r':
            break;
        case 's':
            break;
        case 'q':
            break;
        default:
            break;
        }
    }
}
