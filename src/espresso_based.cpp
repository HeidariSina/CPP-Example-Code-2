#include "espresso_based.h"

EspressoBased::~EspressoBased()
{
    for (const auto &i : ingredients)
        delete i;
    ingredients.clear();
}
double EspressoBased::price()
{
    double money{0};
    for (auto &i : ingredients)
        money = money + i->price();
    return money;
}
std::string EspressoBased::get_name()
{
    return name;
}