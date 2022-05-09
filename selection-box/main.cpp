#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f setRectanglePosition(sf::Vector2i position);

int wWidth = 640;
int wHeight = 480;

int main()
{
    // Main window
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Selection box");

    sf::RectangleShape r1(sf::Vector2f(160.0f, 140.0f));
    r1.setFillColor(sf::Color::Blue);
    r1.setPosition(sf::Vector2f(120.0f, 50.0f));

    sf::Color rectangleColor = sf::Color(0, 255, 21, 10.5); // half transparent green color
    sf::RectangleShape rectangle(sf::Vector2f(0, 0));
    rectangle.setFillColor(rectangleColor);
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setOutlineThickness(1.25f);

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

            else if (event.mouseButton.button == sf::Mouse::Left &&
                     event.type == sf::Event::MouseButtonReleased)
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

        window.draw(r1);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
