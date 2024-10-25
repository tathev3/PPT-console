#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <memory>
#include "Slide.hpp"

namespace Document {

    class Document {
    public:
        void addSlide(const std::string& title, const std::string& content);
        void removeSlide(size_t index);
        void listSlides() const;  
        void clearSlides();        

    private:
        std::vector<std::unique_ptr<Slide>> m_slides;
    };

}

#endif // DOCUMENT_H

