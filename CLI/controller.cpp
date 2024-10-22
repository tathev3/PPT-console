#include "controller.hpp"

Controller::Controller()
    : m_parser{std::make_unique<Parser>()} {
    initialize(); 
}

void Controller::initialize() {
    cli::Slide_Maker::setValidArguments(); 
    cli::Slide_Maker::setValidOptions(); 
}

void Controller::start(std::istream& stream) {
    try {
        while (true) {
            auto command = fetch(stream);
            execute(command); 
        }
    } catch (const Exception& err) {
        std::cerr << err.what() << "\n"; 
    }
}

Controller::CommandPtr Controller::fetch(std::istream& stream) {
    return m_parser->getCommand(stream); 
}

void Controller::execute(CommandPtr& command) {
    command->Execute();
}
