#include <iostream>
#include "include/houses.h"

using namespace houses;

Room::Room(std::string name, double area) {
    this->name = name;
    this->area = area;
}

Room::Room(std::string name, double area, std::string comment) {
    this->name = name;
    this->area = area;
    this->comment = comment;
}

Building::Building(int number, int amount_of_rooms, std::vector<Room> rooms) {
    this->number = number;
    this->amount_of_rooms = amount_of_rooms;
    this->rooms = rooms;
}

double Building::get_area() {
    double area = 0.0;
    for (int i = 0; i < rooms.size(); ++i)
        area += rooms[i].get_area();

    return area;
}

Cottage::Cottage(std::string address, int amount_of_buildings, std::vector<Building> buildings) {
    this->address = address;
    this->amount = amount_of_buildings;
    this->objects = buildings;
}

Appartment::Appartment(std::string address, int amount_of_rooms, std::vector<Room> rooms) {
    this->address = address;
    this->amount = amount_of_rooms;
    this->objects = rooms;
}

Flat::Flat(std::string address, int amount_of_rooms, std::vector<Room> rooms) {
    this->address = address;
    this->amount = 4;
    this->objects = rooms;
}
