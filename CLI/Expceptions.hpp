#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>
#include <source_location>

namespace cli {

class InvalidOption_Cerr : public std::runtime_error {
public:
    InvalidOption_Cerr(const std::string& message, const std::string& option, const std::source_location& location)
        : std::runtime_error(message + ": " + option + " at " + location.file_name() + ":" + std::to_string(location.line())) {}
};

class InvalidArgument_Cerr : public std::runtime_error {
public:
    InvalidArgument_Cerr(const std::string& message, const std::string& argument, const std::source_location& location)
        : std::runtime_error(message + ": " + argument + " at " + location.file_name() + ":" + std::to_string(location.line())) {}
};

} // namespace cli

#endif //EXCEPTIONS_HPP
