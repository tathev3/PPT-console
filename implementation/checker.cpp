#include "checker.hpp"
#include <regex>
#include <iostream>
#include <cctype>

bool Checker::isWord(const std::string& token) {
    std::regex input("^[A-Za-z]+$");
    return std::regex_match(token, input);
}

bool Checker::isArg(const std::string& token) {
    return token[0] == '-' && token.size() > 1;
}

bool Checker::isValue(const std::string& token) {
    std::regex isInt("^-?\\d+$");
    std::regex isDouble("^-?\\d*\\.\\d+$");
    return std::regex_match(token, isInt) || std::regex_match(token, isDouble);
}

bool Checker::isInvalid(const std::string& token) {
    for (char c : token) {
        if (!std::isalnum(c) && c != '-') {
            std::cerr << "Error: Invalid character '" << c << "' in token: " << token << std::endl;
            return true;
        }
    }
    return false;
}
