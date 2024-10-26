#include "Attributes.hpp"

namespace Document {
SlideAttributes::SlideAttributes(const std::string& title, const std::string& backgroundColor)
    : m_Title(title), m_BackgroundColor(backgroundColor) {}

std::string SlideAttributes::getTitle() const {
    return m_Title;
}

std::string SlideAttributes::getBackgroundColor() const {
    return m_BackgroundColor;
}

void SlideAttributes::setTitle(const std::string& title) {
    m_Title = title;
}

void SlideAttributes::setBackgroundColor(const std::string& color) {
    m_BackgroundColor = color;
}


ShapeAttributes::ShapeAttributes(const std::string& type, const std::string& color, std::optional<float> width, std::optional<float> height)
    : m_Type(type), m_Color(color), m_Width(width), m_Height(height) {}

std::string ShapeAttributes::getType() const {
    return m_Type;
}

std::string ShapeAttributes::getColor() const {
    return m_Color;
}

std::optional<float> ShapeAttributes::getWidth() const {
    return m_Width;
}

std::optional<float> ShapeAttributes::getHeight() const {
    return m_Height;
}

void ShapeAttributes::setType(const std::string& type) {
    m_Type = type;
}

void ShapeAttributes::setColor(const std::string& color) {
    m_Color = color;
}

void ShapeAttributes::setWidth(float width) {
    m_Width = width;
}

void ShapeAttributes::setHeight(float height) {
    m_Height = height;
}

} // namespace Document
