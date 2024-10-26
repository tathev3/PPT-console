#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include <string>
#include <vector>
#include <optional>

namespace Document {

class SlideAttributes {
public:
    SlideAttributes(const std::string& title = "", const std::string& backgroundColor = "");

    std::string getTitle() const;
    std::string getBackgroundColor() const;

    void setTitle(const std::string& title);
    void setBackgroundColor(const std::string& color);

private:
    std::string m_Title;        
    std::string m_BackgroundColor;  
};

class ShapeAttributes {
public:
    ShapeAttributes(const std::string& type = "Rectangle", const std::string& color = "Black", std::optional<float> width = std::nullopt, std::optional<float> height = std::nullopt);

    std::string getType() const;
    std::string getColor() const;
    std::optional<float> getWidth() const;
    std::optional<float> getHeight() const;

    void setType(const std::string& type);
    void setColor(const std::string& color);
    void setWidth(float width);
    void setHeight(float height);

private:
    std::string m_Type;     // Type of the shape (e.g., Circle, Rectangle)
    std::string m_Color;   
    std::optional<float> m_Width;  
    std::optional<float> m_Height;  
};

} // namespace Document

#endif 
