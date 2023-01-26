#include <vector>
#ifndef HOUSES_H
#define HOUSES_H

namespace houses {
    /*!
	\brief Класс комнаты
    */
    class Room {
        private:
            std::string name;
            double area;
            std::string comment = "";
        public:
            Room(std::string name, double area);
            Room(std::string name, double area, std::string comment);
            /*!
            Получить название комнаты
            \return название комнаты
            */
            std::string get_name() {return name;}
            /*!
            Получить площадь комнаты
            \return площадь комнаты в м^2
            */
            double get_area() {return area;}
            /*!
            Получить комментарий
            \return комментарий к комнате
            */
            std::string get_comment() {return comment;}
    };

    /*!
	\brief Класс строения
    */
    class Building {
        private:
            int number;
            int amount_of_rooms;
            std::vector<Room> rooms;
        public:
            Building(int number, int amount_of_rooms, std::vector<Room> rooms);
            /*!
            Получить номер строения
            \return номер строения
            */
            int get_number() {return number;}
            /*!
            Получить количество комнаты
            \return количество комнаты
            */
            int get_amount_of_rooms() {return amount_of_rooms;}
            /*!
            Получить комнаты
            \return вектор комнат
            */
            std::vector<Room> get_rooms() {return rooms;}
            /*!
            Получить площадь строения
            \return площадь строения в м^2
            */
            double get_area();
    };

    /*!
	\brief Родительский класс жилого помещения
    */
    template <typename T>
    class BaseAppartment {
        protected:
            std::string address;
            int amount;
            std::vector<T> objects;
        public:
            /*!
            Получить адрес жилого помещения
            \return адрес
            */
            std::string get_address() {return address;}
            /*!
            Получить количество комнат/строений
            \return количество комнат/строений
            */
            int get_amount() {return amount;}
            /*!
            Получить комнаты/строения
            \return вектор комнат/строений
            */
            std::vector<T> get_objects() {return objects;}
            /*!
            Получить площадь комнаты/строения
            \return площадь комнаты/строения в м^2
            */
            double get_area() {
                double area = 0.0;
                for (int i = 0; i < objects.size(); ++i)
                    area += objects[i].get_area();

                return area;
            }
    };

    /*!
	\brief Дочерний класс коттеджа
    */
    class Cottage : public BaseAppartment<Building> {
        public:
            Cottage(std::string address, int amount_of_buildings, std::vector<Building> buildings);
    };

    /*!
	\brief Дочерний класс аппартаментов
    */
    class Appartment : public BaseAppartment<Room> {
        public:
            Appartment(std::string address, int amount_of_rooms, std::vector<Room> rooms);
    };

    /*!
	\brief Дочерний класс квартиры
    */
    class Flat : public BaseAppartment<Room> {
        public:
            Flat(std::string address, int amount_of_rooms, std::vector<Room> rooms);
    };

    /*!
	\brief Класс жилья, которые используется в просматриваемой таблице
    */
    template <typename T>
    class Shelter {
        private:
            bool status_free;
            double price;
            T shelter;
        public:
            Shelter(bool status_free, double price, T shelter) : shelter(shelter.get_address(), shelter.get_amount(), shelter.get_objects()) {
                this->status_free = status_free;
                this->price = price;
                this->shelter = shelter;
            }
            bool get_status_free() {return status_free;}
            std::string get_type() {
                std::string s = typeid(T).name();
                if (s[8] == '4') {
                    return std::string("Квартира");
                } else if (s[8] == '7') {
                    return std::string("Коттедж");
                } else {
                    return std::string("Апартаменты");
                }

            }
            /*!
            Получить стоимость м^2 в рублях
            \return стоимость м^2 в рублях
            */
            double get_price() {return price;}
            /*!
            Получить адрес жилого помещения
            \return адрес
            */
            std::string get_address() {return shelter.get_address();}
            /*!
            Получить площадь жилого помещения в м^2
            \return площадь жилого помещения в м^2
            */
            double get_area() {return shelter.get_area();}
            /*!
            Вывод информации о жилом помещении
            */
            void print_info() {
                std::string type = get_type();
                std::cout << type << " по адресу " << get_address() << "\n";
                std::cout << "Площадь: " << get_area()  << "\n";
                std::cout << "Cтоимость за м^2: " << get_price() << "р\n";
                std::cout << "Кол-во комнат/строений: " << shelter.get_amount() << "\n";
            }
            /*!
            Обновление статуса свободности
            */
            void update_status(bool new_status) {status_free = new_status;}
    };
}
#endif //HOUSES_H