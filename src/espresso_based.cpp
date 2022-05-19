#include "espresso_based.h"

// destructor
EspressoBased::~EspressoBased()
{
    for (const auto &i : ingredients)
        delete i;
    ingredients.clear();
}

// get ingredients
std::vector<Ingredient *> &EspressoBased::get_ingredients()
{
    return ingredients;
}

// constructor
EspressoBased::EspressoBased() : ingredients{} {};

// copy
EspressoBased::EspressoBased(const EspressoBased &esp) : ingredients{esp.ingredients}, name{esp.name} {};

// op =
void EspressoBased::operator=(const EspressoBased &esp)
{
    ingredients = esp.ingredients;
    name = esp.name;
}