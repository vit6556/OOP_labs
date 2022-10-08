#include <iostream>
#include "tractrix/tractrix.h"

double get_square() {
    double square;
    std::cout << "Enter square in degrees: ";
    std::cin >> square;
    return square;
}

double get_tractrix_length() {
    int length;
    std::cout << "Enter tractrix length: ";
    std::cin >> length;
    return length;
}

void menu(tractrix::Tractrix t) {
    const std::string options={"Choose one:\n1) Get tractrix length\n2) Update tractrix length\n3) Get point\n4) Get arc length\n5) Get radius of curvature\n6) Get area of the strip\n7) Get area of the surface of the body of rotation\n8) Get the volume of the rotation body\n9) Exit\n\nYour choice: "};
    int current_state;
    double square, length;

    while (true) {
        std::cout << options;
        std::cin >> current_state;

        if (current_state == 9) return;

        switch(current_state) {
            case 1:
                std::cout << "Tractrix length: " << t.get_length() << "\n\n";
                break;
            case 2: {
                length = get_tractrix_length();
                t.set_length(length);
                break;
            }
            case 3: {
                square = get_square();
                tractrix::Point p = t.get_point(square);
                std::cout << "X: " << p.x << "\n";
                std::cout << "Y: " << p.y << "\n\n";
                break;
            }
            case 4:
                square = get_square();
                std::cout << "Arc length: " << t.get_arc_length(square) << "\n\n";
                break;
            case 5:
                square = get_square();
                std::cout << "Radius of curvature: " << t.get_radius_of_curvature(square) << "\n\n";
                break;
            case 6:
                square = get_square();
                std::cout << "Area of strip: " << t.get_area(square) << "\n\n";
                break;
            case 7:
                square = get_square();
                std::cout << "Area of the surface: " << t.get_area_of_surface(square) << "\n\n";
                break;
            case 8:
                square = get_square();
                std::cout << "Volume: " << t.get_volume(square) << "\n\n";
                break;
            default:
                return;
        }
    }
}

int main() {
    int length = get_tractrix_length();
    tractrix::Tractrix t(length);

    menu(t);
}