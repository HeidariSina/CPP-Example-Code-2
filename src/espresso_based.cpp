#include "espresso_based.h"
#include "sub_ingredients.h"
#include <iostream>
#include <iomanip>

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
// Brew
void EspressoBased::brew()
{
    auto len = name.length();
    int j{0}, k{0};
    int i = 20;
    if ((i - len) % 2 == 0)
    {
        j = (i - len - 2) / 2;
        k = j;
    }
    else
    {
        j = (i - len - 2) / 2;
        k = j + 1;
    }
    std::cout << " ------------------ " << std::endl;
    std::cout << "|                  |" << std::endl;
    std::cout << "|";
    for (; j > 0; j--)
        std::cout << " ";
    std::cout << name;
    for (; k > 0; k--)
        std::cout << " ";
    std::cout << "|" << std::endl;
    std::cout << "|                  |" << std::endl;
    std::cout << "--------------------" << std::endl;
    for (const auto nn : ingredients)
    {
        auto len = nn->get_name().length();
        if ((i - len) % 2 == 0)
        {
            j = (i - len - 2) / 2;
            k = j;
        }
        else
        {
            j = (i - len - 2) / 2;
            k = j + 1;
        }
        std::cout << "|                  |" << std::endl;
        std::cout << "|";
        for (; j > 0; j--)
            std::cout << " ";
        std::cout << nn->get_name();
        for (; k > 0; k--)
            std::cout << " ";
        std::cout << "|" << std::endl;
        std::cout << "|                  |" << std::endl;
    }
    std::cout << " ------------------ " << std::endl;
}
