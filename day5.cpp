#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>

int part1(vector<string> &lines) {

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

