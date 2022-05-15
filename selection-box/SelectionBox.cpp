#include "SelectionBox.h"

SelectionBox::SelectionBox()
{
    size = sf::Vector2f(0.0f, 0.0f);
    startPosition = sf::Vector2f(0.0f, 0.0f);
    endPosition = sf::Vector2f(0.0f, 0.0f);

    backgroundColor = sf::Color(0, 255, 21, 10.5); // half transparent green color
    outlineThickness = 1.25f;
    outlineColor = sf::Color::Green;
    drawing = false;

    rectangle.setSize(size);
    rectangle.setFillColor(backgroundColor);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setOutlineThickness(outlineThickness);
}

SelectionBox::~SelectionBox()
{
    selected_items.clear();
}

int SelectionBox::selectedItemsCount() const
{
    return selected_items.size();
}

void SelectionBox::startDrawing()
{
    drawing = true;
}

void SelectionBox::endDrawing()
{
    drawing = false;
}

void SelectionBox::listen_events(const sf::Event &event, const sf::RenderWindow &window)
{

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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

bool SelectionBox::isDrawing() const
{
    return drawing == true;
}

void SelectionBox::drawBox(sf::RenderWindow &window)
{
    if (isDrawing())
    {
        endPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        size.x = endPosition.x - startPosition.x;
        size.y = endPosition.y - startPosition.y;
    }

    rectangle.setSize(size);
    rectangle.setPosition(startPosition);

    window.draw(rectangle);
}

void SelectionBox::addToSelected(Selectable &item)
{
    selected_items.push_back(item);
}

std::vector<Selectable> SelectionBox::getSelectedItems() const
{

    return selected_items;
}