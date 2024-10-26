#include "Command.hpp"
#include "Exceptions.cpp"

namespace cli {

I_Command::Options I_Command::m_Valid_Options;
I_Command::Arguments I_Command::m_Valid_Arguments;

I_Command::CommandPtr I_Command::create(const Arguments& Function_arguments) {
    const auto arguments = Function_arguments;  
    const auto options = Function_arguments;     

    validateOptions(options);
    validateArguments(arguments);

    return std::make_unique<I_Command>(I_Command(options, arguments));
}

void I_Command::validateOptions(const Options& options) {
    for (const auto& elem : options) {
        if (!m_Valid_Options.contains(elem)) {
            throw InvalidOption_Cerr("Invalid Option", elem, std::source_location::current());
        }
    }
}

void I_Command::validateArguments(const Arguments& arguments) {
    for (const auto& elem : arguments) {
        if (!m_Valid_Arguments.contains(elem)) {
            throw InvalidArgument_Cerr("Invalid Argument", elem, std::source_location::current());
        }
    }
}

void I_Command::Execute() {
    // Execution logic goes here
}

I_Command::I_Command(const Options& options, const Arguments& arguments)
    : m_Options(options), m_Arguments(arguments) {}

void I_Command::setValidOptions(const Options& options) {
    m_Valid_Options = options;
}

void I_Command::setValidArguments(const Arguments& args) {
    m_Valid_Arguments = args;
}

} // namespace cli