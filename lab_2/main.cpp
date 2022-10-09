#include <iostream>
#include <tractrix.h>
#include <menu.h>

int main() {
    int length;
    std::cout << "Enter tractrix length: ";
    std::cin >> length;
    tractrix::Tractrix t(length);
    menu::enter_menu(t);
}