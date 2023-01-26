#include <iostream>
#include <vector>
#include "include/table.h"


using namespace table;


void Table::add_flat(bool status_free, double price, houses::Flat f) {
    houses::Shelter<houses::Flat> s(status_free, price, f);
    flats.push_back(s);
}
void Table::add_appartment(bool status_free, double price, houses::Appartment a) {
    houses::Shelter<houses::Appartment> s(status_free, price, a);
    appatments.push_back(s);
}
void Table::add_cottage(bool status_free, double price, houses::Cottage c) {
    houses::Shelter<houses::Cottage> s(status_free, price, c);
    cottages.push_back(s);
}

void Table::find_by_address(std::string address) {
    bool found = false;
    for (int i = 0; i < flats.size() && !found; ++i) {
        if (flats[i].get_address() == address) {
            std::cout << "Найден ";
            flats[i].print_info();
            found = true;
            break;
        }
    }

    for (int i = 0; i < appatments.size() && !found; ++i) {
        if (appatments[i].get_address() == address) {
            std::cout << "Найден ";
            appatments[i].print_info();
            found = true;
            break;
        }
    }

    for (int i = 0; i < cottages.size() && !found; ++i) {
        if (cottages[i].get_address() == address) {
            std::cout << "Найден ";
            cottages[i].print_info();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Жилье не найдено\n";
    }

    std::cout << "\n";
}

void Table::update_status(std::string address, bool status) {
    for (int i = 0; i < flats.size() ++i) {
        if (flats[i].get_address() == address) {
            flats[i].update_status(status);
            return;
        }
    }

    for (int i = 0; i < appatments.size(); ++i) {
        if (appatments[i].get_address() == address) {
            appatments[i].update_status(status);
            return;
        }
    }

    for (int i = 0; i < cottages.size(); ++i) {
        if (cottages[i].get_address() == address) {
            cottages[i].update_status(status);
            return;
        }
    }
}


void Table::show_all_shelters() {
    std::cout << "Квартиры:\n";
    if (flats.size() == 0) std::cout << "Квартир не найдено\n";
    for (int i = 0; i < flats.size(); ++i) {
        if (flats[i].get_status_free()) {
            flats[i].print_info();
            std::cout << "\n";
        }
    }

    std::cout << "\nАпартаменты:\n";
    if (appatments.size() == 0) std::cout << "Апартаментов не найдено\n";
    for (int i = 0; i < appatments.size(); ++i) {
        if (appatments[i].get_status_free()) {
            appatments[i].print_info();
            std::cout << "\n";
        }
    }

    std::cout << "\nКоттеджи:\n";
    if (cottages.size() == 0) std::cout << "Коттеджей не найдено\n";
    for (int i = 0; i < cottages.size(); ++i) {
        if (cottages[i].get_status_free()) {
            cottages[i].print_info();
            std::cout << "\n";
        }
    }
}
