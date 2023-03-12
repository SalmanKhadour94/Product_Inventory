#include "Inventory.h"

    Invendory::Invendory() { fill_inventory_vector(); }
    void  Invendory::inventory_menu()
    {
        string menu_option_string;
        int menu_option_int;

        cout << " " << endl;
        cout << "INVENTORY MANAGEMENT: " << endl;
        cout << " " << endl;
        cout << "1. Add a product " << endl;
        cout << "2. Delete a product" << endl;
        cout << "3. Find product information" << endl;
        cout << "4. Print all products" << endl;
        cout << "5. Sum up the inventory value" << endl;
        cout << "6. Modify product information" << endl;
        cout << "7. Exit" << endl;
        cout << " " << endl;
        cout << "your option: ";

        cin >> menu_option_string;
        menu_option_int = atoi(menu_option_string.c_str());

        switch (menu_option_int)
        {
        case 1:
            system("cls");
            add_product();
            break;
        case 2:
            system("cls");
            remove_product();
            break;
        case 3:
            system("cls");
            find_product();
            break;
        case 4:
            system("cls");
            print_all_products();
            break;
        case 5:
            system("cls");
            sum_inventory();
            break;
        case 6:
            system("cls");
            modify_product();
            break;
        case 7:
            exit(0);
        default:
            cout << " " << endl;
            cout << "!!! NOT A VALID OPTION !!! " << endl;
            cout << " " << endl;
            inventory_menu();
            break;
        }

    }
    void  Invendory::print_all_products()
    {
        printout_inventory_vector();

        cout << " " << endl;
        cout << " Enter any letter or number to stop viewing " << endl;
        cout << " " << endl;

        string key;

        while (1)
        {
            cin >> key;
            if (!key.empty())
            {
                break;
            }
        }

        system("cls");
        inventory_menu();

    }
    void  Invendory::add_product()
    {
        string product_name;
        float product_price;
        int quantity_available;

        cout << "ENTER NEW PRODUCT TO THE INVENTORY         " << endl;
        cout << "Product name: ";
        cin >> product_name;
        cout << "Product price: ";
        cin >> product_price;
        cout << "Quantity available: ";
        cin >> quantity_available;

        Product newProduct(product_name, product_price, quantity_available);
        m_inventory.push_back(newProduct);
        newProduct.print_product();

        ofstream inventory_file("inventory.txt", ios::app);

        if (inventory_file.is_open())
        {
            inventory_file << newProduct.get_productName() << " " << newProduct.get_productID() << " " << newProduct.get_productPrice() << " " << newProduct.get_quantityAvailable() << endl;

            inventory_file.close();

        }
        else
        {
            std::cout << "Error opening the file" << endl;
        }

        cout << " " << endl;
        cout << " Enter any letter or number to stop viewing " << endl;
        cout << " " << endl;

        string key;
        while (1)
        {
            cin >> key;
            if (!key.empty())
            {
                break;
            }
        }
        system("cls");
        inventory_menu();

    }
    void  Invendory::find_product()
    {
        int input_id;
        cout << "Enter product ID: ";
        cin >> input_id;
        cout << " " << endl;

        fstream inventory_file("inventory.txt", ios::in);
        string product_name;
        int product_id;
        float product_price;
        int quantity_available;
        bool found = false;


        if (inventory_file.is_open())
        {
            while (inventory_file >> product_name >> product_id >> product_price >> quantity_available)
            {
                if (product_id == input_id)
                {
                    Product product(product_name, product_id, product_price, quantity_available);
                    product.print_product();
                    found = true;
                }
            }
            inventory_file.close();
        }
        else
        {
            std::cout << "Error opening the file" << endl;
        }
        if (found == false)
        {
            cout << "PRODUCT NOT FOUND " << endl;
        }
        cout << " " << endl;
        cout << " Enter any letter or number to stop viewing " << endl;
        cout << " " << endl;

        string key;
        while (1)
        {
            cin >> key;
            if (!key.empty())
            {
                break;
            }
        }

        system("cls");
        inventory_menu();

    }
    void  Invendory::remove_product()
    {
        fstream temp_file("temp_file.txt", ios::out | ios::trunc);
        fstream inventory_file("inventory.txt", ios::in);
        string product_name;
        int product_id;
        float product_price;
        int quantity_available;
        int input_id;
        Product p;
        cout << "Enter an ID of a product to be removed: ";
        cin >> input_id;
        cout << " " << endl;

        if (inventory_file.is_open() && temp_file.is_open())
        {
            while (inventory_file >> product_name >> product_id >> product_price >> quantity_available)
            {
                if (input_id != product_id)
                {
                    temp_file << product_name << " " << product_id << " " << product_price << " " << quantity_available << endl;
                }
                else
                {
                    p.set_productName(product_name);
                    p.set_productID(product_id);
                    p.set_productPrice(product_price);
                    p.set_quantityAvailable(quantity_available);
                }

            }
            inventory_file.close();
            temp_file.close();

            remove("inventory.txt");
            if (rename("temp_file.txt", "inventory.txt") != 0)
                perror("Error renaming file");

        }
        else
        {
            std::cout << "Error opening the file" << endl;
        }

        m_inventory.clear();
        fill_inventory_vector();
        cout << " " << endl;
        cout << "REMOVED PRODUCT INFORMATION: " << endl;
        p.print_product();
        cout << " " << endl;
        cout << " Enter any letter or number to stop viewing " << endl;
        cout << " " << endl;

        string key;
        while (1)
        {
            cin >> key;
            if (!key.empty())
            {
                break;
            }
        }

        system("cls");
        inventory_menu();


    }
    void  Invendory::modify_product()
    {
        Product product;
        string modify_option_string;
        int modify_option_int;
        int input_id;
        cout << "Enter an ID of a product to modify: ";
        cin >> input_id;
        cout << " " << endl;

        fstream inventory_file("inventory.txt", ios::in);
        string product_name;
        int product_id;
        float product_price;
        int quantity_available;
        bool found = false;


        if (inventory_file.is_open())
        {
            while (inventory_file >> product_name >> product_id >> product_price >> quantity_available)
            {
                if (product_id == input_id)
                {
                    product.set_productName(product_name);
                    product.set_productID(product_id);
                    product.set_productPrice(product_price);
                    product.set_quantityAvailable(quantity_available);

                    product.print_product();
                    found = true;
                }
            }
            inventory_file.close();
        }
        else
        {
            std::cout << "Error opening the file" << endl;
        }
        if (found == false)
        {
            cout << "PRODUCT NOT FOUND " << endl;

            cout << " " << endl;
            cout << " Enter any letter or number to stop viewing " << endl;
            cout << " " << endl;

            string key;
            while (1)
            {
                cin >> key;
                if (!key.empty())
                {
                    break;
                }
            }

            system("cls");
            inventory_menu();

        }

        cout << " " << endl;
        cout << "MODIFY A PRODUCT: " << endl;
        cout << " " << endl;
        cout << "1. Modify product's price " << endl;
        cout << "2. Modify the quantity of a product" << endl;
        cout << "3. Go back to the main menu" << endl;
        cout << "  " << endl;
        cout << "your option:  ";

        cin >> modify_option_string;
        modify_option_int = atoi(modify_option_string.c_str());
        switch (modify_option_int)
        {
        case 1:
            system("cls");
            float new_product_price;
            cout << "Input the new price of the product: ";
            cin >> new_product_price;
            modify_price(new_product_price, product);
            break;
        case 2:
            system("cls");
            int new_quantity_available;
            cout << "Input the new available quantity of the product: ";
            cin >> new_quantity_available;
            modify_quantity(new_quantity_available, product);
            break;
        case 3:
            system("cls");
            inventory_menu();
            break;
        default:
            cout << " " << endl;
            cout << "!!! NOT A VALID OPTION !!! " << endl;
            cout << " " << endl;
            modify_product();
            break;
        }

    }
    void  Invendory::modify_price(float& new_price, Product& product)
    {
        system("cls");
        fstream temp_file("temp_file.txt", ios::out | ios::trunc);
        fstream inventory_file("inventory.txt", ios::in);
        string product_name;
        int product_id;
        float product_price;
        int quantity_available;

        if (inventory_file.is_open() && temp_file.is_open())
        {
            while (inventory_file >> product_name >> product_id >> product_price >> quantity_available)
            {
                if (product.get_productID() != product_id)
                {
                    temp_file << product_name << " " << product_id << " " << product_price << " " << quantity_available << endl;
                }
                else
                {
                    temp_file << product_name << " " << product_id << " " << new_price << " " << quantity_available << endl;
                }

            }
            inventory_file.close();
            temp_file.close();

            remove("inventory.txt");
            if (rename("temp_file.txt", "inventory.txt") != 0)
                perror("Error renaming file");

        }
        else
        {
            std::cout << "Error opening the file" << endl;
        }

        m_inventory.clear();
        fill_inventory_vector();

        product.set_productPrice(new_price);
        product.print_product();
        cout << " " << endl;
        cout << " Enter any letter or number to stop viewing " << endl;
        cout << " " << endl;

        string key;
        while (1)
        {
            cin >> key;
            if (!key.empty())
            {
                break;
            }
        }

        system("cls");
        inventory_menu();
    }
    void  Invendory::modify_quantity(int& new_quantity, Product& product)
    {
        system("cls");
        fstream temp_file("temp_file.txt", ios::out | ios::trunc);
        fstream inventory_file("inventory.txt", ios::in);
        string product_name;
        int product_id;
        float product_price;
        int quantity_available;

        if (inventory_file.is_open() && temp_file.is_open())
        {
            while (inventory_file >> product_name >> product_id >> product_price >> quantity_available)
            {
                if (product.get_productID() != product_id)
                {
                    temp_file << product_name << " " << product_id << " " << product_price << " " << quantity_available << endl;
                }
                else
                {
                    temp_file << product_name << " " << product_id << " " << product_price << " " << new_quantity << endl;
                }

            }
            inventory_file.close();
            temp_file.close();

            remove("inventory.txt");
            if (rename("temp_file.txt", "inventory.txt") != 0)
                perror("Error renaming file");

        }
        else
        {
            std::cout << "Error opening the file" << endl;
        }

        m_inventory.clear();
        fill_inventory_vector();

        product.set_quantityAvailable(new_quantity);
        product.print_product();
        cout << " " << endl;
        cout << " Enter any letter or number to stop viewing " << endl;
        cout << " " << endl;

        string key;
        while (1)
        {
            cin >> key;
            if (!key.empty())
            {
                break;
            }
        }

        system("cls");
        inventory_menu();
    }
    void  Invendory::sum_inventory()
    {
        unsigned int inventory_size = (unsigned int)m_inventory.size();
        int number_of_all_products = 0;
        double value_of_all_products = 0;
        for (unsigned int i = 0;i < inventory_size;i++)
        {
            number_of_all_products += m_inventory[i].get_quantityAvailable();
            value_of_all_products += (m_inventory[i].get_quantityAvailable() * m_inventory[i].get_productPrice());
        }
       
        cout << " " << endl;
        cout << "INVENTORY SUM UP: " << endl;
        cout << " " << endl;
        cout << "NUMBER OF ALL PRODUCTS: " << number_of_all_products << endl;
        cout << "VALUE OF ALL PRODUCTS: " << value_of_all_products << endl;
        cout << " " << endl;    

        cout << " " << endl;
        cout << " Enter any letter or number to stop viewing " << endl;
        cout << " " << endl;

        string key;
        while (1)
        {
            cin >> key;
            if (!key.empty())
            {
                break;
            }
        }

        system("cls");
        inventory_menu();

    }
    void  Invendory::fill_inventory_vector()
    {
        fstream inventory_file("inventory.txt", ios::in);
        string product_name;
        int product_id;
        float product_price;
        int quantity_available;

        if (inventory_file.is_open())
        {
            while (inventory_file >> product_name >> product_id >> product_price >> quantity_available)
            {
                Product newProduct(product_name, product_id, product_price, quantity_available);
                m_inventory.push_back(newProduct);
            }
            inventory_file.close();
        }
        else
        {
            cout << "Error opening the file" << endl;
        }

    }
    void  Invendory::printout_inventory_vector()
    {
        int inventory_size = (int)m_inventory.size();
        for (int i = 0;i < inventory_size;i++)
        {
            m_inventory[i].print_product();
        }

    }