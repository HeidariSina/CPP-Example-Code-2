#include "cappuccino.h"

// constructor
Cappuccino::Cappuccino() : EspressoBased()
{
    this->name = "Cappuccino";
    this->ingredients.push_back(new Espresso{2});
    this->ingredients.push_back(new Milk{2});
    this->ingredients.push_back(new MilkFoam{1});
}

// copy
Cappuccino::Cappuccino(const Cappuccino &cap)
{
    name = cap.name;
    ingredients = cap.ingredients;
    side_items = cap.side_items;
}

// deconstructor
Cappuccino::~Cappuccino()
{
    for (const auto &i : ingredients)
        delete i;
    ingredients.clear();
    for (const auto &i : side_items)
        delete i;
    side_items.clear();
}
