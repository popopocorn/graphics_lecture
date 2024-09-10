#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<cctype>
#include<print>
#include<algorithm>


bool compare_string(std::string first, std::string second) {
    std::transform(first.begin(), first.end(), first.begin(), tolower);
    std::transform(second.begin(), second.end(), second.begin(), tolower);
    if (first.compare(second) == 0) {
        return true;
    }
    else {
        return false;
    }

}


class sentences
{
private:
    std::string sentence[10];
    bool has_color = false;
    bool has_reverse_line = false;
    bool has_insert_at = false;
    bool has_reverse_space = false;
    bool has_change = false;
    int has_print_sort = 0;
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
    void change( char change_word, char target_word);
    void print();
    void print_sort();
    void find_word(std::string find_words);
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
        bool color_flag = false;
        for (int line = 0; line < 10; ++line) {
            for (int words = 0; words < sentence[line].length(); ++words) {
                if (words == 0) {
                    if (isupper(sentence[line][words]) != 0) {
                        color_flag = true;
                    }
                }
                else {
                    if (sentence[line][words] == ' ') {
                        color_flag = false;
                    }
                    if (sentence[line][words - 1] == ' ' && isupper(sentence[line][words]) != 0) {
                        color_flag=true;
                    }
                }
                if (color_flag) {
                    
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    std::cout << sentence[line][words];
                    
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    std::cout << sentence[line][words];
                }               
            }
            std::cout << "\n";
        }
        has_color = !has_color;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void sentences::reverse_line() {
    if (has_reverse_line) {
        for (int line = 0; line < 10; ++line) {
            for (int words = 0; words < sentence[line].length(); ++words) {
                std::cout << sentence[line][words];
            }
            std::cout << '\n';
        }
        has_reverse_line = !has_reverse_line;
    }
    else {
        for (int line = 0; line < 10; ++line) {
            for (int words = sentence[line].length(); words > -1; --words) {
                std::cout << sentence[line][words];
            }
            std::cout << '\n';
        }
        has_reverse_line = !has_reverse_line;
    }
}
void sentences::insert_at() {
    if (has_insert_at) {
        for (int line = 0; line < 10; ++line) {
            for (int words = 0; words < sentence[line].length(); ++words) {
                std::cout << sentence[line][words];
            }
            std::cout << '\n';
        }
        has_insert_at = !has_insert_at;
    }
    else {
        int count_words = 0;
        for (int line = 0; line < 10; ++line) {
            for (int words = 0; words < sentence[line].length(); ++words) {
                ++count_words;
                std::cout << sentence[line][words];
                if (count_words == 3) {
                    std::cout << "@@";
                    count_words = 0;
                }
            }
            std::cout << '\n';
        }
        has_insert_at = !has_insert_at;
    }
}
void sentences::reverse_space() {
    if (has_reverse_space) {
        for (int line = 0; line < 10; ++line) {
            for (int words = 0; words < sentence[line].length(); ++words) {
                std::cout << sentence[line][words];
            }
            std::cout << '\n';
        }
        has_reverse_space = !has_reverse_space;
    }
    else {
        int first_space = 0;
        int second_space = 0;
        int temp = 0;
        for (int line = 0; line < 10; ++line) {
            for (int words = 0; words < sentence[line].length(); ++words) {
                if (sentence[line][words] == ' ') {
                    temp = words;
                    while (true) {
                        --temp;
                        
                        std::cout << sentence[line][temp];
                        if (temp == 0 || sentence[line][temp - 1] == ' ') {
                            break;
                        }
                        
                    }
                    std::cout << ' ';
                }
                else if (words == sentence[line].length() - 1) {
                    temp = words;
                    std::cout << sentence[line][words];
                    while (true) {
                        --temp;

                        std::cout << sentence[line][temp];
                        if (temp == 0 || sentence[line][temp - 1] == ' ') {
                            break;
                        }
                    }
                }


            }
            std::cout << '\n';
        }
        has_reverse_space = !has_reverse_space;

    }
}
void sentences::change(char change_word, char target_word) {
    if (has_change) {
        
        for (int line = 0; line < 10; ++line) {
            for (int words = 0; words < sentence[line].length(); ++words) {
                std::cout << sentence[line][words];
            }
            std::cout << '\n';
        }

        has_change = !has_change;
    }
    else {
        for (int line = 0; line < 10; ++line) {
            for (int words = 0; words < sentence[line].length(); ++words) {
                if (sentence[line][words] == target_word) {
                    std::cout << change_word;
                }
                else {
                    std::cout << sentence[line][words];
                }
            }
            std::cout << '\n';
        }



        has_change = !has_change;
    }
}
void sentences::print() {
    int count = 1;
    for (int line = 0; line < 10; ++line) {
        for (int words = 0; words < sentence[line].length(); ++words) {
            std::cout << sentence[line][words];
            if (sentence[line][words] == ' ') {
                ++count;
            }
        }
        std::cout << "  단어 수: " << count;
        std::cout << '\n';
        count = 1;
    }
}

void sentences::print_sort() {
    int rank[10]{};
    int count = 1;
    int index_save[10]{};
    int max_value{};
    int max_index{};
    for (int line = 0; line < 10; ++line) {
        for (int words = 0; words < sentence[line].length(); ++words) {
            if (sentence[line][words] == ' ') {
                ++count;
            }
        }
        rank[line] = count;
        count = 1;
    }
    for (int r = 0; r < 10; ++r) {
        max_value = -1;
        for (int line = 0; line < 10; ++line) {
            if (rank[line] > max_value) {
                max_value = rank[line];
                max_index = line;
            }
        }
        index_save[r] = max_index;
        rank[max_index] = -1;
    }
    switch (has_print_sort) {
    case 0:
        for (int rank = 9; rank >-1; --rank) {
            std::cout << sentence[index_save[rank]] << '\n';
        }
        
        has_print_sort = 1;
        break;

    case 1:
        for (int rank = 0; rank <10; ++rank) {
            std::cout << sentence[index_save[rank]] << '\n';
        }

        has_print_sort = 2;
        break;

    case 2:
        for (int line = 0; line < 10; ++line) {
            std::cout << sentence[line] << '\n';
        }
        has_print_sort = 0;
        break;

    }
}
void sentences::find_word(std::string find_words) {
    int count{};
    int temp{0};
    std::string slice_sen{};
    for (int line = 0; line < 10; ++line) {
        temp = 0;
        for (int words = 0; words < sentence[line].length(); ++words) {
            if(sentence[line][words]==' '){
                slice_sen = sentence[line].substr(temp, words-temp);
                if (compare_string(slice_sen, find_words)) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    std::cout << slice_sen << ' ';
                    ++count;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    std::cout << slice_sen << ' ';
                }
                temp = words + 1;
            }
            else if (words == sentence[line].length() - 1) {
                slice_sen = sentence[line].substr(temp);
                if (compare_string(slice_sen, find_words)) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    std::cout << slice_sen;
                    ++count;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    std::cout << slice_sen;
                }
            }
        }
        std::cout << " 같은 단어의 개수: " << count;
        std::cout << '\n';
        count = 0;
    }
}




int main() {
    sentences s;
    s.print_4_debug();
    char menu;
    char in_word;
    char out_word;
    bool has_g = false;
    std::string find_target{};
    while(true){
        std::cout << "실행할 명령을 입력하시오: ";
        std::cin >> menu;
        while (getchar() != '\n');
        switch (menu) {
        case 'c':
            s.color();
            std::cout << '\n';
            break;

        case 'd':
            s.reverse_line();
            std::cout << '\n';
            break;
        case 'e':
            s.insert_at();
            std::cout << '\n';
            break;
        case 'f':
            s.reverse_space();
            std::cout << '\n';
            break;
        case 'g':
        if(!has_g){
            std::cout << "바꿀 목표 바꿀 단어 순으로 입력하시오: ";
            std::cin >> in_word >> out_word;
        }
            s.change(out_word, in_word);
            std::cout << '\n';
            has_g = !has_g;
            break;
        case 'h':
            s.print();
            std::cout << '\n';
            break;
        case 'r':
            s.print_sort();
            std::cout << '\n';
            break;
        case 's':
            std::cout << "찾을 단어를 입력하시오: ";
            std::getline(std::cin, find_target);
            s.find_word(find_target);
            std::cout << '\n';
            break;
        case 'q':
            return 0;
            break;
        default:
            break;
        }
    }
}
