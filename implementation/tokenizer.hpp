#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <memory>
#include <string>
#include "token.hpp"
#include "checker.hpp"

class Tokenizer {
public:
    std::vector<std::unique_ptr<Token>> tokenize(const std::string& input);

private:
    Checker checker;
};

#endif // TOKENIZER_H
