#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f setRectanglePosition(sf::Vector2i position);

int wWidth = 640;
int wHeight = 480;

int main()
{
    // Main window
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "First window");

    // objects
    sf::RectangleShape rectangle(sf::Vector2f(0, 0));
    rectangle.setFillColor(sf::Color::Green);

    bool drawing = false;
    sf::Vector2f rSize = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f startPosition = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f endPosition = sf::Vector2f(0.0f, 0.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (drawing == false)
                {
                    startPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                    drawing = true;
                }
            }

            else if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased)
            {
                drawing = false;
            }
        }

        if (drawing == true)
        {
            sf::Vector2i mp = sf::Mouse::getPosition(window);
            endPosition = static_cast<sf::Vector2f>(mp);
            rSize.x = endPosition.x - startPosition.x;
            rSize.y = endPosition.y - startPosition.y;
        }

        window.clear(sf::Color::Black);

        rectangle.setSize(rSize);
        rectangle.setPosition(startPosition);

        window.draw(rectangle);
        window.display();
    }

    return 0;
}
