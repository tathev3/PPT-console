#ifndef SLIDEMAKER_H
#define SLIDEMAKER_H

#include "./CLI/Command.hpp"
#include "Document.hpp"
#include <iostream>

namespace cli {

    class SlideMaker : public I_Command {
    public:
        SlideMaker(const Options& options, const Arguments& arguments, Document::Document& document)
            : I_Command(options, arguments), m_document(document) {}

        static CommandPtr create(const Options& options, const Arguments& arguments, Document::Document& document) {
            return std::make_unique<SlideMaker>(options, arguments, document);
        }

        void Execute() override;

        static void initializeValidCommands();

    private:
        Document::Document& m_document; // Reference to the Document object
    };

}

#endif // SLIDEMAKER_H

