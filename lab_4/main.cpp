#include <iostream>
#include <vector>
#include <string>
#include <houses.h>
#include <table.h>

using namespace houses;

int main() {
    std::vector<Room> rooms_1;
    rooms_1.push_back(Room(std::string("Гостинная"), 12.5, std::string("Очень крутая гостинная")));
    rooms_1.push_back(Room(std::string("Кухня"), 10));
    rooms_1.push_back(Room(std::string("Спальня"), 13, std::string("Большая кровать")));

    std::vector<Room> rooms_2;
    rooms_2.push_back(Room(std::string("Гостинная"), 20, std::string("Большая гостинная")));
    rooms_2.push_back(Room(std::string("Кухня"), 15, std::string("Современная кухня")));
    rooms_2.push_back(Room(std::string("Спальня"), 14, std::string("Есть большой телевизор")));
    rooms_2.push_back(Room(std::string("Коридор"), 10, std::string("Большой коридор")));

    std::vector<Building> buildings;
    buildings.push_back(Building(1, 3, rooms_1));
    buildings.push_back(Building(2, 4, rooms_2));

    Cottage c = Cottage(std::string("ул. Лужники, 24"), 2, buildings);
    Flat f = Flat(std::string("ул. Лужники, 23"), 4, rooms_2);

    table::Table t;
    t.add_cottage(false, 20000, c);
    t.add_flat(true, 10000, f);
    t.find_by_address(std::string("ул. Лужники, 24"));
    t.show_all_shelters();

    t.update_status(std::string("ул. Лужники, 24"), true);
    t.show_all_shelters();
}