#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <memory>
#include <string>
#include "tokenizer.hpp"

class Lexer {
public:
    std::vector<std::unique_ptr<Token>> processInput(const std::string& input);

private:
    Tokenizer tokenizer;
};

#endif // LEXER_H
