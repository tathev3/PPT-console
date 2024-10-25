#ifndef SLIDE_H
#define SLIDE_H

#include <string>

namespace Document {

    class Slide {
    public:
        Slide(const std::string& title, const std::string& content);
        std::string getTitle() const;
        std::string getContent() const;

    private:
        std::string m_title;
        std::string m_content;
    };

}

#endif // SLIDE_H
