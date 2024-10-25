#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "CommandCreator.h"
#include "Document.h"

namespace cli {

    class Controller {
    public:
        Controller();
        void start();
        void fetch();
        void execute(const CommandInfo& commandInf);
        CommandInfo parseCommand(const std::string& commandLine);

    private:
        std::unique_ptr<CommandCreator> m_parser;
        Document::Document m_document; // Document object to manage slides
    };

}

#endif // CONTROLLER_H



