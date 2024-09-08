#include<iostream>
#include<fstream>
#include<string>

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
};

void sentences::color() {

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
   
}
