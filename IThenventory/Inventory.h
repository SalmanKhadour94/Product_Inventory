#pragma once
#include <vector>
#include "Product.h"

class Invendory
{
    vector<Product> m_inventory;
public:
    Invendory();
    void inventory_menu();
    void print_all_products();
    void add_product();
    void find_product();
    void remove_product();
    void modify_product();
    void modify_price(float& new_price, Product& product);
    void modify_quantity(int& new_quantity, Product& product);
    void sum_inventory();
    void fill_inventory_vector();
    void printout_inventory_vector();
};