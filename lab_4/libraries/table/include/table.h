#include <vector>
#include <houses.h>
#ifndef TABLE_H
#define TABLE_H

namespace table {
    /*!
	\brief Класс таблицы
    */
    class Table {
        private:
            std::vector<houses::Shelter<houses::Flat>> flats;
            std::vector<houses::Shelter<houses::Appartment>> appatments;
            std::vector<houses::Shelter<houses::Cottage>> cottages;
        public:
            /*!
            Добавить квартиру
            */
            void add_flat(bool status_free, double price, houses::Flat f);
            /*!
            Добавить аппартаменты
            */
            void add_appartment(bool status_free, double price, houses::Appartment a);
            /*!
            Добавить коттедж
            */
            void add_cottage(bool status_free, double price, houses::Cottage c);
            /*!
            Найти жилье по адресу
            */
            void find_by_address(std::string address);
            /*!
            Показать все доступное жилье
            */
            void show_all_shelters();
            /*!
            Обновить занятость квартиры по адресу
            */
            void update_status(std::string address);
    };
}

#endif //TABLE_H