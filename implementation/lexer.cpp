#include "lexer.hpp"
#include <vector>

std::vector<std::unique_ptr<Token>> Lexer::processInput(const std::string& input) {
    return tokenizer.tokenize(input);
}
