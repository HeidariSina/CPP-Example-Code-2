#include <iostream>
#include <gtest/gtest.h>
#include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"
#include "cappuccino.h"
#include "mocha.h"

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        EspressoBased *esp{new Cappuccino{}};
        reinterpret_cast<Cappuccino *>(esp)->add_side_item(new Cookie{1});
        std::vector<Ingredient *> &sides = reinterpret_cast<Cappuccino *>(esp)->get_side_items();
        std::cout << sides.size() << std::endl;
        delete esp;
        std::cout << sides.size() << std::endl;
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}