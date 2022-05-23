#include "espresso_based.h"
#include <iostream>

// constructor
EspressoBased::EspressoBased() : ingredients{} {}

// copy
EspressoBased::EspressoBased(const EspressoBased &esp)
{
    ingredients = esp.ingredients;
    name = esp.name;
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
