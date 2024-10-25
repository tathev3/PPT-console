#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <unordered_set>
#include <memory>
#include <stdexcept>
#include <source_location>

namespace cli {

    using Options = std::unordered_set<std::string>;
    using Arguments = std::unordered_set<std::string>;

    class I_Command {
    public:
        using CommandPtr = std::unique_ptr<I_Command>;

        I_Command(const Options& options, const Arguments& arguments);

        static void setValidOptions(const Options& options);
        static void setValidArguments(const Arguments& args);
        static CommandPtr create(const Arguments& Function_arguments);

        virtual void Execute();

    private:
        static Options m_Valid_Options;
        static Arguments m_Valid_Arguments;
        Options m_Options;
        Arguments m_Arguments;

        static void validateOptions(const Options& options);
        static void validateArguments(const Arguments& arguments);
    };

    class InvalidOption_Cerr : public std::runtime_error {
    public:
        InvalidOption_Cerr(const std::string& message, const std::string& option, const std::source_location& location)
            : std::runtime_error(message + ": " + option) {}
    };

    class InvalidArgument_Cerr : public std::runtime_error {
    public:
        InvalidArgument_Cerr(const std::string& message, const std::string& argument, const std::source_location& location)
            : std::runtime_error(message + ": " + argument) {}
    };

} // namespace cli

#endif // COMMAND_H

