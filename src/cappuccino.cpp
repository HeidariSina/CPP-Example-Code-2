#include "cappuccino.h"
#include <iostream>

// constructor
Cappuccino::Cappuccino() : EspressoBased()
{
    name = "Cappuccino";
    ingredients.push_back(new Espresso{2});
    ingredients.push_back(new Milk{2});
    ingredients.push_back(new MilkFoam{1});
    side_items = {};
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
    for (auto &i : side_items)
    {
        i = nullptr;
        delete i;
    }
    side_items.clear();
}

// op =
void Cappuccino::operator=(const Cappuccino &cap)
{
    name = cap.name;
    ingredients = cap.ingredients;
    side_items = cap.side_items;
}

// get name
std::string Cappuccino::get_name() { return name; }

// price
double Cappuccino::price()
{
    double money{0};
    for (const auto &i : ingredients)
        money += i->price();
    for (const auto &i : side_items)
        money += i->price();
    return money;
}

// add side items
void Cappuccino::add_side_item(Ingredient *side)
{
    side_items.push_back(side);
}

// get side items
std::vector<Ingredient *> &Cappuccino::get_side_items()
{
    return side_items;
}