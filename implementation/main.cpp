#include <iostream>
#include "parser.hpp"

int main() {
    Parser parser;
    std::string input;

    std::cout << "Enter a command: ";
    std::getline(std::cin, input);

    parser.parse(input);
    return 0;
}
