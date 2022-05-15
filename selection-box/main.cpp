#include <iostream>
#include <SFML/Graphics.hpp>
#include "SelectionBox.h"

sf::Vector2f setRectanglePosition(sf::Vector2i position);

int wWidth = 640;
int wHeight = 480;

int main()
{
    // Main window
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Selection box");

    // example rectangle
    sf::RectangleShape r1(sf::Vector2f(160.0f, 140.0f));
    r1.setFillColor(sf::Color::Blue);
    r1.setPosition(sf::Vector2f(120.0f, 50.0f));

    // selection box;
    SelectionBox selectionBox;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            selectionBox.listen_events(event, window);
        }

        window.clear(sf::Color::Black);
        window.draw(r1);

        selectionBox.drawBox(window);
        window.display();
    }

    return 0;
}
