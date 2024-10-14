#include "token.hpp"

Token::Token(token type, std::variant<std::string, int, double> content)
    : _type(type), _content(content) {}
