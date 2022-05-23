#include "espresso_based.h"
#include "sub_ingredients.h"
#include <iostream>

// constructor
EspressoBased::EspressoBased() : ingredients{} {}

// copy
EspressoBased::EspressoBased(const EspressoBased &esp)
{
    ingredients.clear();
    name = esp.name;
    for (const auto i : esp.ingredients)
    {
        auto name = i->get_name();
        auto unit = i->get_units();
        if (name == "Cinnamon")
            ingredients.push_back(new Cinnamon{unit});
        if (name == "Chocolate")
            ingredients.push_back(new Chocolate{unit});
        if (name == "Sugar")
            ingredients.push_back(new Sugar{unit});
        if (name == "Cookie")
            ingredients.push_back(new Cookie{unit});
        if (name == "Espresso")
            ingredients.push_back(new Espresso{unit});
        if (name == "Milk")
            ingredients.push_back(new Milk{unit});
        if (name == "MilkFoam")
            ingredients.push_back(new MilkFoam{unit});
        if (name == "Water")
            ingredients.push_back(new Water{unit});
    }
};
// destructor
EspressoBased::~EspressoBased()
{
    for (auto &i : ingredients)
    {
        i = nullptr;
        delete i;
    }
    ingredients.clear();
}
// get ingredients
std::vector<Ingredient *> &EspressoBased::get_ingredients()
{
    return ingredients;
}
// op =
void EspressoBased::operator=(const EspressoBased &esp)
{
    ingredients = esp.ingredients;
    name = esp.name;
}
