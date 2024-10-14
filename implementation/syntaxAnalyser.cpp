#include "syntaxAnalyser.hpp"
#include <iostream>

void SyntaxAnalyser::processTokens(const std::vector<std::unique_ptr<Token>>& tokens) {
    if (tokens.empty() || tokens[0]->_type == Token::EOL) {
        std::cerr << "Error: No valid input provided." << std::endl;
        return;
    }

    if (tokens[0]->_type != Token::Word) {
        std::cerr << "Error: Input must begin with a command (a word)." << std::endl;
        return;
    }

    for (size_t i = 1; i < tokens.size(); ++i) {
        const Token& current = *tokens[i];
        const Token& previous = *tokens[i - 1];

        switch (current._type) {
            case Token::Arg:
                if (previous._type != Token::Word) {
                    std::cerr << "Error: An argument must follow a command." << std::endl;
                    return;
                }
                break;
            case Token::Value:
                if (previous._type != Token::Arg) {
                    std::cerr << "Error: A value must follow an argument." << std::endl;
                    return;
                }
                break;

            case Token::EOL:
                std::cout << "Input successfully processed." << std::endl;
                return;

            default:
                std::cerr << "Error: Unexpected token type." <<std::endl;
                return;
        }
    }
}
