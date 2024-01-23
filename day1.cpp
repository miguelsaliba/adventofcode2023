#include <iostream>
#include <string>
#include <sstream>
#include <istream>
#include <vector>
#include <unordered_map>
using std::vector;
using std::istream;
using std::stringstream;
using std::string;

int chartoint(char c) {
    return c - '0';
}

std::unordered_map<string, int> word_numbers = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"zero", 0},
};

int part1(string &line) {
    int sum = 0;
    int left = line.length();
    int right = left;
    for (int i = 0; i < line.length(); i++) {
        if (isdigit(line.at(i))) {
            left = i;
            break;
        }
    }
    for (int i = line.length() - 1; i >= left; i--) {
        if (isdigit(line.at(i))) {
            right = i;
            break;
        }
    }
    return chartoint(line.at(left)) * 10 + chartoint(line.at(right));
}

int part2(vector<string> lines) {
    int sum = 0;
    for (string line : lines) {
        int left = line.length()-1;
        int right = 0;
        int left_number = 0;
        int right_number = 0;
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line.at(i))) {
                left = i;
                left_number = chartoint(line.at(i));
                break;
            }
        }
        for (int i = line.length() - 1; i >= left; i--) {
            if (isdigit(line.at(i))) {
                right = i;
                right_number = chartoint(line.at(i));
                break;
            }
        }
        for (auto number : word_numbers) {
            int index = line.find(number.first);
            if (index != -1 && index < left) {
                left = index;
                left_number = number.second;
            }
            index = line.rfind(number.first);
            if (index != -1 && index > right) {
                right = index;
                right_number = number.second;
            }
        }
        sum += left_number * 10 + right_number;
    }
    return sum;
}

int main() {
//    string input;
//    int sum = 0;
//    while (input != "0") {
//        std::cin >> input;
//        sum += part1(input);
//    }
//    std::cout << "Answer: " << sum << std::endl;
    string input;
    vector<string> lines;
    while (input != "0") {
        std::cin >> input;
        lines.emplace_back(input);
    }
    std::cout << "Answer: " << part2(lines) << std::endl;
    return 0;
}