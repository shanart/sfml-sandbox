#ifndef SELECTION_BOX_H_
#define SELECTION_BOX_H_

#include <SFML/Graphics.hpp>

class SelectionBox
{
private:
    sf::RectangleShape rectangle;

    // appearence
    sf::Color backgroundColor;
    sf::Color outlineColor;
    double outlineThickness;

    // sizes
    sf::Vector2f size;
    sf::Vector2f startPosition;
    sf::Vector2f endPosition;

public:
    bool drawing;
    SelectionBox();

    void startDrawing();
    void endDrawing();
    bool isDrawing() const;

    void listen_events(const sf::Event &event, const sf::RenderWindow &window);
    void drawBox(sf::RenderWindow &window);
};

#endif // SELECTION_BOX_H_
