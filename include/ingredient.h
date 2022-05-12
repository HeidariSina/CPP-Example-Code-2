#ifndef INGREDIENT_H
#define INGREDIENT_H

class Ingredient
{
public:
    double get_price_unit();
    size_t get_units();
    std::string get_name();

    double price();

protected:
    Ingredient(double price_unit, size_t units);

    double price_unit;
    size_t units;
    std::string name;
};

double Ingredient::get_price_unit() { return price_unit; }
size_t Ingredient::get_units() { return units; }
std::string Ingredient::get_name() { return name; }
double Ingredient::price() { return price_unit * units; }

#endif // INGREDIENT_H