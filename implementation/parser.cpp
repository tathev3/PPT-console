#include "parser.hpp"

void Parser::parse(const std::string& input) {
    std::vector<std::unique_ptr<Token>> tokens = lexer.processInput(input);
    if (!tokens.empty()) {
        syntaxAnalyser.processTokens(tokens);
    }
}
