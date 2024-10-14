#ifndef SYNTAX_ANALYSER_H
#define SYNTAX_ANALYSER_H

#include <vector>
#include <memory>
#include "token.hpp"

class SyntaxAnalyser {
public:
    void processTokens(const std::vector<std::unique_ptr<Token>>& tokens);
};

#endif // SYNTAX_ANALYSER_H
