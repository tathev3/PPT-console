#ifndef CHECKER_H
#define CHECKER_H

#include <string>

class Checker {
public:
    bool isWord(const std::string& token);
    bool isArg(const std::string& token);
    bool isValue(const std::string& token);
    bool isInvalid(const std::string& token);
};

#endif // CHECKER_H
