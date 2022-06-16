#include <iostream>
#include <SFML/Graphics.hpp>

int wWidth = 640;
int wHeight = 480;

int main()
{
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Cannons, loader and storage");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}
