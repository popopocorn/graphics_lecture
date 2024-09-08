#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<cctype>
class sentences
{
private:
    std::string sentence[10];
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
    void color(int selected);
    void reverse_line(int selected);
    void insert_at(int selected);
    void reverse_space(int selected);
    void change(int selected);
    void print();
    void print_sort(int selected);
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

void sentences::color(int selected) {
    if(){
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < sentence[i].length(); ++j) {
                if (j == 0) {
                    if (isupper(sentence[i][j] != 0)) {
                        //첫단어 대문자일때 출력
                    }
                    else {
                        //첫단어 대문자 아닐때 출력
                    }
                }
                else {
                    if (sentence[i][j - 1] == ' ') {
                        if (isupper(sentence[i][j]) != 0) {
                            //나머지 단어가 대문자일때 출력
                        }
                        else {
                            //나머지 단어가 대문자 아닐때 출력
                        }
                    }

                }
            }
        }
    }
}
void sentences::reverse_line(int selected) {

}
void sentences::insert_at(int selected) {

}
void sentences::reverse_space(int selected) {

}
void sentences::change(int selected) {

}
void sentences::print() {
  
}

void sentences::print_sort(int selected) {

}
void sentences::find_word() {

}

int main() {
    sentences s;
    s.print_4_debug();
}
