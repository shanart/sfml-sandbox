#ifndef SELECTION_BOX_H_
#define SELECTION_BOX_H_

#include <iostream>
#include <SFML/Graphics.hpp>

// Not all objects can be selected. So they has to be marked as Selectable

class Selectable
{
public:
    bool selectable;
    Selectable() { selectable = true; }
};

class SelectionBox
{
private:
    sf::RectangleShape rectangle;
    bool drawing;

    // appearence
    sf::Color backgroundColor;
    sf::Color outlineColor;
    double outlineThickness;

    // sizes
    sf::Vector2f size;
    sf::Vector2f startPosition;
    sf::Vector2f endPosition;

    // selected items
    // https://www.programiz.com/cpp-programming/vectors
    std::vector<Selectable> selected_items;

    void addToSelected(Selectable &item);

public:
    SelectionBox();
    ~SelectionBox();
    int selectedItemsCount() const;

    void startDrawing();
    void endDrawing();
    bool isDrawing() const;

    // List getSelectedItems();
    std::vector<Selectable> getSelectedItems() const;

    void listen_events(const sf::Event &event, const sf::RenderWindow &window);
    void drawBox(sf::RenderWindow &window);
};

#endif // SELECTION_BOX_H_
