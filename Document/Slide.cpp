#include "Slide.h"

namespace Document {

    Slide::Slide(const std::string& title, const std::string& content)
        : m_title(title), m_content(content) {}

    std::string Slide::getTitle() const {
        return m_title;
    }

    std::string Slide::getContent() const {
        return m_content;
    }

}
