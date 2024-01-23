#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
#include <sstream>

const int RED = 12;
const int GREEN = 13;
const int BLUE = 14;

int part1(vector<string> lines) {
    int sum = 0;
    for (string &line : lines) {
        bool is_valid = true;
        int game_number = atoi(&line.at(5));
        line.erase(0, line.find(':') + 1);
        std::stringstream game(line);
        string set;
        while (getline(game, set, ';')) {
            string set_part;
            std::stringstream set_stream(set);

            while (getline(set_stream, set_part, ',')) {
                size_t space_pos = set_part.find(' ', 1);
                string color = set_part.substr(space_pos+1);
                int count = atoi(&set_part.at(1));
//                std::cout << count << ' ' << color << std::endl;

                if (color == "red")
                    if (count > RED)
                         is_valid = false;
                if (color == "blue")
                    if (count > BLUE)
                        is_valid = false;
                if (color == "green")
                    if (count > GREEN)
                        is_valid = false;
            }
        }
        if (is_valid)
            sum += game_number;
    }
    return sum;
}

int part2(vector<string> lines) {
    int sum = 0;
    for (string &line : lines) {
        int game_number = atoi(&line.at(5));
        line.erase(0, line.find(':') + 1);
        int max_red = 0;
        int max_green = 0;
        int max_blue = 0;

        std::stringstream game(line);
        string set;
        while (getline(game, set, ';')) {
            string set_part;
            std::stringstream set_stream(set);

            while (getline(set_stream, set_part, ',')) {
                size_t space_pos = set_part.find(' ', 1);
                string color = set_part.substr(space_pos+1);
                int count = atoi(&set_part.at(1));
//                std::cout << count << ' ' << color << std::endl;

                if (color == "red")
                    if (count > max_red)
                        max_red = count;
                if (color == "blue")
                    if (count > max_blue)
                        max_blue = count;
                if (color == "green")
                    if (count > max_green)
                        max_green = count;
            }
        }
        sum += max_blue * max_green * max_red;
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