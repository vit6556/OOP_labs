#include <gtest/gtest.h>
#include <string>
#include <houses.h>

using namespace houses;

TEST(Classes, Room) {
    Room r = Room(std::string("Гостинная"), 12.5, std::string("Очень крутая гостинная"));

    ASSERT_EQ(r.get_name(), std::string("Гостинная"));
    ASSERT_EQ(r.get_area(), 12.5);
    ASSERT_EQ(r.get_comment(), std::string("Очень крутая гостинная"));
}

TEST(Classes, Building) {
    std::vector<Room> rooms_1;
    rooms_1.push_back(Room(std::string("Гостинная"), 12.5, std::string("Очень крутая гостинная")));
    rooms_1.push_back(Room(std::string("Кухня"), 10));
    rooms_1.push_back(Room(std::string("Спальня"), 13, std::string("Большая кровать")));

    Building b = Building(1, 3, rooms_1);
    ASSERT_EQ(b.get_number(), 1);
    ASSERT_EQ(b.get_amount_of_rooms(), 3);
    ASSERT_EQ(b.get_area(), 35.5);
}

TEST(Classes, Cottage) {
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

    ASSERT_EQ(c.get_address(), std::string("ул. Лужники, 24"));
    ASSERT_EQ(c.get_amount(), 2);
    ASSERT_EQ(c.get_area(), 94.5);
}

TEST(Classes, Appartment) {
    std::vector<Room> rooms;
    rooms.push_back(Room(std::string("Гостинная"), 12.5, std::string("Очень крутая гостинная")));
    rooms.push_back(Room(std::string("Кухня"), 10));
    rooms.push_back(Room(std::string("Спальня"), 13, std::string("Большая кровать")));

    Appartment a = Appartment(std::string("ул. Лужники, 24"), 3, rooms);

    ASSERT_EQ(a.get_address(), std::string("ул. Лужники, 24"));
    ASSERT_EQ(a.get_amount(), 3);
    ASSERT_EQ(a.get_area(), 35.5);
}

TEST(Classes, Flat) {
    std::vector<Room> rooms;
    rooms.push_back(Room(std::string("Гостинная"), 20, std::string("Большая гостинная")));
    rooms.push_back(Room(std::string("Кухня"), 15, std::string("Современная кухня")));
    rooms.push_back(Room(std::string("Спальня"), 14, std::string("Есть большой телевизор")));
    rooms.push_back(Room(std::string("Коридор"), 10, std::string("Большой коридор")));

    Flat f = Flat(std::string("ул. Лужники, 24"), 4, rooms);

    ASSERT_EQ(f.get_address(), std::string("ул. Лужники, 24"));
    ASSERT_EQ(f.get_amount(), 4);
    ASSERT_EQ(f.get_area(), 59);
}

TEST(Classes, Shelter) {
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
    Shelter<Cottage> s(true, 10000, c);

    ASSERT_EQ(s.get_address(), std::string("ул. Лужники, 24"));
    ASSERT_EQ(s.get_price(), 10000);
    ASSERT_EQ(s.get_area(), 94.5);
    ASSERT_EQ(s.get_status_free(), true);
    ASSERT_EQ(s.get_type(), std::string("Коттедж"));
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}