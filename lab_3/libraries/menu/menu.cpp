#include <iostream>
#include <diagram.h>
#include "include/menu.h"

diagram::Diagram *menu::create_diagram() {
    const std::string options={"Choose one:\n1) Default values\n2) Const values\n3) ASCII values\n\nYour choice: "};
    int current_state;

    while (true) {
        std::cout << options;
        std::cin >> current_state;

        switch(current_state) {
            case 1: {
                diagram::Diagram *d = new diagram::Diagram();
                return d;
            }
            case 2: {
                int length = 0;
                while (length < 1) {
                    std::cout << "Enter diagram length: ";
                    std::cin >> length;
                }

                char value = 'Y';
                while (value != '0' && value != '1' && value != 'X') {
                    std::cout << "Enter signal value: ";
                    std::cin >> value;
                }

                int signal_length = 0;
                while (signal_length < 1) {
                    std::cout << "Enter signal length: ";
                    std::cin >> signal_length;
                }

                diagram::Diagram *d = new diagram::Diagram(length, value, signal_length);
                return d;
            }
            case 3: {
                int length = 0;
                while (length < 1) {
                    std::cout << "Enter diagram length: ";
                    std::cin >> length;
                }

                std::string values = "";
                while (values.length() != length) {
                    std::cout << "Enter signal values: ";
                    std::cin >> values;
                }

                int signal_length = 0;
                while (signal_length < 1) {
                    std::cout << "Enter signal length: ";
                    std::cin >> signal_length;
                }

                diagram::Diagram *d = new diagram::Diagram(length, values, signal_length);
                return d;
            }
            default:
                break;
        }
    }
}


void menu::enter_menu() {
    const std::string options={"Choose one:\n1) Create diagram\n2) Print current diagram\n3) Rotate left\n4) Rotate right\n5) Update signal\n6) Copy diagram\n7) Concat with other diagram\n8) Exit\n\nYour choice: "};
    int current_state;
    double square, length;

    diagram::Diagram *d = new diagram::Diagram();

    while (true) {
        std::cout << options;
        std::cin >> current_state;

        if (current_state == 8) break;

        switch(current_state) {
            case 1:
                delete d;
                d = create_diagram();
                break;
            case 2:
                std::cout << "Current diagram: ";
                d->print();
                std::cout << "\n";
                break;
            case 3: {
                int amount = 0;
                while (amount < 1) {
                    std::cout << "Enter amount of rotation: ";
                    std::cin >> amount;
                }
                d->rotate_left(amount);
                break;
            }
            case 4: {
                int amount = 0;
                while (amount < 1) {
                    std::cout << "Enter amount of rotation: ";
                    std::cin >> amount;
                }
                d->rotate_right(amount);
                break;
            }
            case 5:  {
                int index = -1;
                while (index < 0) {
                    std::cout << "Enter signal index: ";
                    std::cin >> index;
                }

                char value = 'Y';
                while (value != '0' && value != '1' && value != 'X') {
                    std::cout << "Enter signal value: ";
                    std::cin >> value;
                }

                int signal_length = 0;
                while (signal_length < 1) {
                    std::cout << "Enter signal length: ";
                    std::cin >> signal_length;
                }

                d->update_signal(index, value, signal_length);
                break;
            }
            case 6: {
                int amount = 0;
                while (amount < 1) {
                    std::cout << "Enter amount copies: ";
                    std::cin >> amount;
                }
                d->copy(amount);
                break;
            }
            case 7: {
                diagram::Diagram *d1 = create_diagram();
                d = *d + d1;
                delete d1;
                break;
            }
            default:
                break;
        }
    }
    delete d;
}