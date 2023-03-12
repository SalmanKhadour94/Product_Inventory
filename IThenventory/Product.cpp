#include "Product.h"

void Product:: generate_id()
{
    fstream inventory_file("inventory.txt", ios::in);
    string product_name;
    int product_id = 0;
    float product_price;
    int quantity_available;


    if (inventory_file.is_open())
    {
        while (inventory_file >> product_name >> product_id >> product_price >> quantity_available)
        {

        }
        inventory_file.close();
    }
    else
    {
        std::cout << "Error opening the file" << endl;
    }
    m_product_id = product_id + 1;

}
Product::Product() { m_product_name = "name";m_product_id = 0;m_product_price = 0;m_quantity_available = 0; }
Product::Product(string product_name, float product_price, int quantity_available)
        :m_product_name(product_name), m_product_price(product_price), m_quantity_available(quantity_available)
    {
        generate_id();
    }
Product::Product(string product_name, int product_id, float product_price, int quantity_available)
        :m_product_name(product_name), m_product_id(product_id), m_product_price(product_price), m_quantity_available(quantity_available) { }
string  Product::get_productName() const { return m_product_name; }
float  Product::get_productPrice() const { return m_product_price; }
int  Product::get_productID() const { return m_product_id; }
int  Product::get_quantityAvailable() const { return m_quantity_available; }
void  Product::set_productName(const string& product_name) { m_product_name = product_name; }
void  Product::set_productPrice(const float& product_price) { m_product_price = product_price; }
void  Product::set_productID(const int& product_id) { m_product_id = product_id; }
void  Product::set_quantityAvailable(const int& quantity_available) { m_quantity_available = quantity_available; }
void  Product::print_product() {
    cout << " " << endl;
    cout << "PRODUCT DESCRIPTION: " << endl;
    cout << " " << endl;
    cout << "Product name: " << m_product_name << endl;
    cout << "Product ID: " << m_product_id << endl;
    cout << "Product price: " << m_product_price << endl;
    cout << "Quantity available: " << m_quantity_available << endl;
    cout << " " << endl;
    }