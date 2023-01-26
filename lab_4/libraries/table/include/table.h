#include <vector>
#include <houses.h>
#ifndef TABLE_H
#define TABLE_H

namespace table {
    class Table {
        private:
            std::vector<houses::Shelter<houses::Flat>> flats;
            std::vector<houses::Shelter<houses::Appartment>> appatments;
            std::vector<houses::Shelter<houses::Cottage>> cottages;
        public:
            void add_flat(bool status_free, double price, houses::Flat f);
            void add_appartment(bool status_free, double price, houses::Appartment a);
            void add_cottage(bool status_free, double price, houses::Cottage c);
            void find_by_address(std::string address);
            void show_all_shelters();
            void free_shelter(std::string address);
    };
}

#endif //TABLE_H