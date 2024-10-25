#include "Controller.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>

namespace cli {

    Controller::Controller() {
        SlideMaker::initializeValidCommands(); // Initialize valid commands and options
        m_parser = std::make_unique<CommandCreator>();
    }

    void Controller::start() {
        std::cout << "Welcome to the Slide Presentation CLI! Type 'exit' to quit.\n";

        while (true) {
            std::string commandLine;
            std::cout << "> "; // Prompt for command input
            std::getline(std::cin, commandLine);

            // Exit the program if the user types 'exit'
            if (commandLine == "exit") break;

            // Parse the command line into command name, options, and arguments
            CommandInfo commandInf = parseCommand(commandLine);
            fetch();
            execute(commandInf);
        }
    }

    void Controller::fetch() {
        // Logic to fetch commands (could be expanded as needed)
        std::cout << "Fetching commands...\n";
    }

    void Controller::execute(const CommandInfo& commandInf) {
        try {
            auto commandPtr = m_parser->CreateCommand(commandInf);
            commandPtr->Execute();
            std::cout << "Executed command: " << commandInf.getInfo() << "\n";
        } catch (const std::exception& ex) {
            std::cerr << "Error executing command: " << ex.what() << "\n";
        }
    }

    CommandInfo Controller::parseCommand(const std::string& commandLine) {
        std::istringstream stream(commandLine);
        std::string commandName;
        std::unordered_set<std::string> options;
        std::vector<std::string> arguments;

        // Extract the command name (first word)
        stream >> commandName;

        // Extract options (starting with '-')
        std::string token;
        while (stream >> token) {
            if (token[0] == '-') {
                options.insert(token);
            } else {
                arguments.push_back(token);
            }
        }

        return CommandInfo(commandName, options, arguments);
    }

} // namespace cli




