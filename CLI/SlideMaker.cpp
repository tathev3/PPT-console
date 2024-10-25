#include "SlideMaker.hpp"

namespace cli {

    void SlideMaker::Execute() {
        // Check if the command is to list slides
        if (m_Arguments.size() == 1 && m_Arguments[0] == "list") {
            m_document.listSlides(); // List the slides
            return;
        }

        // Example: Create a slide with options and arguments
        std::string title = m_Arguments.size() > 0 ? m_Arguments[0] : "Untitled Slide";
        std::string content = m_Options.size() > 0 ? m_Options.begin()->c_str() : "Default Content";
        
        m_document.addSlide(title, content);
    }

    void SlideMaker::initializeValidCommands() {
        Options validOptions = { "-title" }; // must be change
        I_Command::setValidOptions(validOptions);

        Arguments validArguments = { "pos", "list" }; // must be change
        I_Command::setValidArguments(validArguments);
    }

}

