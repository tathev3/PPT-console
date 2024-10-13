#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <memory>
#include <sstream>
#include <variant>

class Token {
public:
    enum token {
        Word,
        Arg,
        Value,
        EOL
    } _type;

    std::variant<std::string, int, double> _content;

    Token(token type, std::variant<std::string, int, double> content)
        : _type(type), _content(content) {}
};

class Checker {
public:
    bool isWord(const std::string& token);
    bool isArg(const std::string& token);
    bool isValue(const std::string& token);
    bool isInvalid(const std::string& token);
};

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
        if (!std::isalnum(c) && c != '-')
            return true;
    }
    return false;
}

class Tokenizer {
public:
    std::vector<std::unique_ptr<Token>> tokenize(const std::string& input);

private:
    Checker checker;
};

std::vector<std::unique_ptr<Token>> Tokenizer::tokenize(const std::string& input) {
    std::vector<std::unique_ptr<Token>> tokens;
    std::string token;
    std::istringstream stream(input);

    while (stream >> token) {
        if (checker.isInvalid(token)) {
            std::cerr << "Invalid token: " << token << std::endl;
            continue;
        }

        if (checker.isWord(token)) {
            tokens.push_back(std::make_unique<Token>(Token::Word, token));
        } else if (checker.isArg(token)) {
            tokens.emplace_back(std::make_unique<Token>(Token::Arg, token));
        } else if (checker.isValue(token)) {
            if (token.find('.') != std::string::npos) {
                tokens.emplace_back(std::make_unique<Token>(Token::Value, std::stod(token)));
            } else {
                tokens.emplace_back(std::make_unique<Token>(Token::Value, std::stoi(token)));
            }
        } else {
            std::cerr << "Unexpected token: " << token << std::endl;
        }
    }

    tokens.emplace_back(std::make_unique<Token>(Token::EOL, ""));

    return tokens;
}




    




