#include "tokenizer.hpp"
#include <sstream>
#include <iostream>
#include <vector>

std::vector<std::unique_ptr<Token>> Tokenizer::tokenize(const std::string& input) {
    std::vector<std::unique_ptr<Token>> tokens;
    std::string token;
    std::istringstream stream(input);

    while (stream >> token) {
        if (checker.isInvalid(token)) continue;

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
