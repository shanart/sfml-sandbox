#ifndef SELECTION_BOX_H_
#define SELECTION_BOX_H_

#include <SFML/Graphics.hpp>

class SelectionBox
{
private:
    //  = sf::Color(0, 255, 21, 10.5);
    sf::Color r_color;
    //  = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f r_size;

public:
    SelectionBox();

    void start_drawing();
    void end_drawing();
};

#endif // SELECTION_BOX_H_