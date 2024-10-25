#ifndef COMMANDCREATOR_H
#define COMMANDCREATOR_H

#include "Command.hpp"
#include <unordered_map>
#include <functional>
#include <string>
#include <stdexcept>
#include <source_location>

namespace cli {

    class CommandCreator {
    public:
        using Key = std::string;
        using Value = std::function<I_Command::CommandPtr(const Arguments&)>;
        using CommandPtr = I_Command::CommandPtr;

        CommandCreator();
        CommandPtr CreateCommand(const CommandInfo& commandInf);

    private:
        std::unordered_map<Key, Value> m_validCommands;

        const Value getFunction(const Key& key);
        void setValidCommands();
    };

    class InvalidCommand_Cerr : public std::runtime_error {
    public:
        InvalidCommand_Cerr(const std::string& message, const std::string& command, const std::source_location& location)
            : std::runtime_error(message + ": " + command) {}
    };

} // namespace cli

#endif // COMMANDCREATOR_H

