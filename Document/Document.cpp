#include "Document.h"
#include <iostream>

namespace Document {

    void Document::addSlide(const std::string& title, const std::string& content) {
        m_slides.push_back(std::make_unique<Slide>(title, content));
        std::cout << "Slide added: " << title << "\n";
    }

    void Document::removeSlide(size_t index) {
        if (index < m_slides.size()) {
            m_slides.erase(m_slides.begin() + index);
            std::cout << "Slide removed at index: " << index << "\n";
        } else {
            std::cout << "Invalid slide index: " << index << "\n";
        }
    }

    void Document::listSlides() const {
        if (m_slides.empty()) {
            std::cout << "No slides available.\n";
            return;
        }

        std::cout << "Slides:\n";
        for (size_t i = 0; i < m_slides.size(); ++i) {
            std::cout << "[" << i << "] " << m_slides[i]->getTitle() << ": " << m_slides[i]->getContent() << "\n";
        }
    }

    void Document::clearSlides() {
        m_slides.clear();
        std::cout << "All slides cleared.\n";
    }

}
