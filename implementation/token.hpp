#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <variant>

class Token {
public:
    enum token { Word, Arg, Value, EOL } _type;
    std::variant<std::string, int, double> _content;

    Token(token type, std::variant<std::string, int, double> content);
};

#endif // TOKEN_H
