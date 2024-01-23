#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;

int part1 (vector<string> &lines) {
    int sum = 0;
    string token;
    for (string &line : lines) {
        int score = 0;
        string numbers = line.substr(line.find(':') + 1);
        std::stringstream ss(numbers);
        vector<int> winning_numbers;
        while (!ss.eof()) {
            ss >> token;
            if (token == "|") { break; }
            winning_numbers.emplace_back(stoi(token));
        }
        while (!ss.eof()) {
            ss >> token;
            if (std::find(winning_numbers.begin(), winning_numbers.end(), stoi(token)) != winning_numbers.end()) {
               score = score == 0 ? 1 : score * 2;
            }
        }
        sum += score;
    }
    return sum;
}

int part2 (vector<string> &lines) {
    int sum = 0;
    string token;
    vector<int> instances(lines.size());

    for (string &line : lines) {
        int card = atoi(&line.at(5));
        instances[card-1] += 1;
        string numbers = line.substr(line.find(':') + 1);
        std::stringstream ss(numbers);
        vector<int> winning_numbers;
        while (!ss.eof()) {
            ss >> token;
            if (token == "|") {
                break;
            }
            winning_numbers.emplace_back(stoi(token));
        }
        int matches = 0;
        while (!ss.eof()) {
            ss >> token;
            if (std::find(winning_numbers.begin(), winning_numbers.end(), stoi(token)) != winning_numbers.end()) {
                matches++;
            }
        }
        for (int i = 0; i < matches; i++) {
            instances[card+i] += instances[card-1];
        }
        sum += instances[card-1];
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
    std::cout << "Answer: " << part2(result) << std::endl;
    return 0;
}
