#include "CommandCreator.hpp"
#include "CommandInfo.hpp"
#include "SlideMaker.hpp" // Assuming you have a SlideMaker class to create slides

cli::CommandCreator::CommandCreator() {
    setValidCommands();
}

const cli::CommandCreator::Value cli::CommandCreator::getFunction(const Key& key) {
    if (m_validCommands.contains(key)) {
        return m_validCommands[key];
    }
    throw cli::InvalidCommand_Cerr("Invalid command name", key, std::source_location::current());
}

cli::CommandCreator::CommandPtr cli::CommandCreator::CreateCommand(const CommandInfo& commandInf) {
    const auto[name, options, arguments] = commandInf.getInfo();
    Value funcPtr;

    try {
        funcPtr = getFunction(name);
    } catch (cli::InvalidCommand_Cerr& err) {
        throw;
    }

    return std::move(funcPtr(arguments));
}

void cli::CommandCreator::setValidCommands() {
    const auto val = cli::SlideMaker::create; // Assuming SlideMaker has a static create method
    m_validCommands["makeslide"] = std::move(val);
}

