#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>

int length(int number) {
    int len = 0;
    do {
        ++len;
        number /= 10;
    } while (number);
    return len;
}

bool symbol_around(int y, int x, size_t len, vector<string> &lines) {
    int x_start = std::max(0, x-1);
    int x_end = std::min(lines[0].length(), x+len+1);
    int y_start = std::max(0, y-1);
    int y_end = std::min((int) lines.size(), y+2);
    for (int i = y_start; i < y_end; i++) {
        for (int j = x_start; j < x_end; j++) {
            char c = lines[i].at(j);
            if (!isdigit(c) && c != '.') {
                return true;
            }
        }
    }
    return false;
}

bool star_around(int y, int x, size_t len, vector<string> &lines) {
    int x_start = std::max(0, x-1);
    int x_end = std::min(lines[0].length(), x+len+1);
    int y_start = std::max(0, y-1);
    int y_end = std::min((int) lines.size(), y+2);
    for (int i = y_start; i < y_end; i++) {
        for (int j = x_start; j < x_end; j++) {
            char c = lines[i].at(j);
            if (c == '*') {
                return true;
            }
        }
    }
    return false;
}

int part1(vector<string> &lines) {
    int sum = 0;
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].length(); j++) {
            if (!isdigit(lines[i].at(j))) {
                continue;
            }
            int number = atoi(&lines[i].at(j));
            int len = length(number);
            if (symbol_around(i, j, len, lines)) {
                sum += number;
            }
            j += len;
        }
    }
    return sum;
}

int part2(vector<string> &lines) {
    int sum = 0;
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].length(); j++) {
            if (!isdigit(lines[i].at(j))) {
                continue;
            }
            int number = atoi(&lines[i].at(j));
            int len = length(number);
            if (star_around(i, j, len, lines)) {
                sum += number;
            }
            j += len;
        }
    }
    return sum;
}

int main() {
    string input;
    vector<string> result;
    getline(std::cin, input);
    while (input != "0") {
        result.emplace_back(input);
        getline(std::cin, input);
    }
    std::cout << "Answer: " << part1(result) << std::endl;
    return 0;
}