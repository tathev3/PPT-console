#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <memory>
#include "lexer.hpp"
#include "syntaxAnalyser.hpp"

class Parser {
private:
    Lexer lexer;
    SyntaxAnalyser syntaxAnalyser;

public:
    void parse(const std::string& input);
};

#endif // PARSER_H
