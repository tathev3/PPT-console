#include "Command.hpp"

cli::I_Command::Options cli::I_Command::m_Valid_Options;
cli::I_Command::Arguments cli::I_Command::m_Valid_Arguments;

cli::I_Command::I_Command(const Options& options, const Arguments& arguments) {
    m_Options = options;
    m_Arguments = arguments;
}

void cli::I_Command::setValidOptions(const Options& options) {
    m_Valid_Options = options;
}

void cli::I_Command::setValidArguments(const Arguments& args) {
    m_Valid_Arguments = args;
}

cli::I_Command::CommandPtr cli::I_Command::create(const Arguments& Function_arguments) {
    const auto arguments = Function_arguments;  // Assuming Function_arguments is already a set of strings
    const auto options = Function_arguments;     // Assuming Function_arguments contains options as well

    try {
        validateOptions(options);
        validateArguments(arguments);
    } catch (const std::exception& err) {
        throw;
    }
    return std::move(std::make_unique<cli::I_Command>(I_Command(options, arguments)));
}

void cli::I_Command::validateOptions(const Options& options) {
    for (const auto& elem : options) {
        if (!m_Valid_Options.contains(elem)) {
            throw cli::InvalidOption_Cerr("Invalid Option", elem, std::source_location::current());
        }
    }
}

void cli::I_Command::validateArguments(const Arguments& arguments) {
    for (const auto& elem : arguments) {
        if (!m_Valid_Arguments.contains(elem)) {
            throw cli::InvalidArgument_Cerr("Invalid Argument", elem, std::source_location::current());
        }
    }
}

void cli::I_Command::Execute() {
    return;
}

