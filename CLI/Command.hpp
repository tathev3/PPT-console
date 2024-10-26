#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include <set>
#include <string>
#include "Exceptions.hpp" 

namespace cli {

class I_Command {
public:
    using Options = std::set<std::string>;
    using Arguments = std::set<std::string>;
    using CommandPtr = std::unique_ptr<I_Command>;

    static CommandPtr create(const Arguments& Function_arguments);
    void Execute();

    static void setValidOptions(const Options& options);
    static void setValidArguments(const Arguments& args);

protected:
    I_Command(const Options& options, const Arguments& arguments);

private:
    static Options m_Valid_Options;
    static Arguments m_Valid_Arguments;

    Options m_Options;
    Arguments m_Arguments;

    static void validateOptions(const Options& options);
    static void validateArguments(const Arguments& arguments);
};

} // namespace cli


#endif // COMMAND_H

