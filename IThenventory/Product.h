#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
class Product
{
private:
    string m_product_name;
    int m_product_id = 0;
    float m_product_price;
    int m_quantity_available;
    void generate_id();
public:
    Product();
    Product(string product_name, float product_price = 0, int quantity_available = 0);
    Product(string product_name, int product_id, float product_price, int quantity_available);
    string get_productName() const;
    float get_productPrice() const;
    int get_productID() const;
    int get_quantityAvailable() const;
    void set_productName(const string& product_name);
    void set_productPrice(const float& product_price);
    void set_productID(const int& product_id);
    void set_quantityAvailable(const int& quantity_available);
    void print_product();
};