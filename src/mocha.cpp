#include "mocha.h"
#include <iostream>

// constructor
Mocha::Mocha() : EspressoBased()
{
    name = "Mocha";
    ingredients.push_back(new Espresso{2});
    ingredients.push_back(new Milk{2});
    ingredients.push_back(new MilkFoam{1});
    ingredients.push_back(new Chocolate{1});
    side_items = {};
}

// copy
Mocha::Mocha(const Mocha &cap)
{
    name = cap.name;
    ingredients = cap.ingredients;
    side_items = cap.side_items;
}

// deconstructor
Mocha::~Mocha()
{
    for (auto &i : side_items)
    {
        i = nullptr;
        delete i;
    }
    side_items.clear();
}

// op =
void Mocha::operator=(const Mocha &cap)
{
    name = cap.name;
    ingredients = cap.ingredients;
    side_items = cap.side_items;
}

// get name
std::string Mocha::get_name() { return name; }

// price
double Mocha::price()
{
    double money{0};
    for (const auto &i : ingredients)
        money += i->price();
    for (const auto &i : side_items)
        money += i->price();
    return money;
}

// add side items
void Mocha::add_side_item(Ingredient *side)
{
    side_items.push_back(side);
}

// get side items
std::vector<Ingredient *> &Mocha::get_side_items()
{
    return side_items;
}
