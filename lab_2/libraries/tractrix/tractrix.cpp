#include <iostream>
#include <cmath>
#include "include/tractrix.h"

#define square_radians square*M_PI/180

using namespace tractrix;

Tractrix::Tractrix() {
    set_length(0);
}

Tractrix::Tractrix(double l) {
    set_length(l);
}

void Tractrix::set_length(double l) {
    length = l;
}

double Tractrix::get_length() {
    return length;
}

Point Tractrix::get_point(double square) {
    Point p;
    p.x = length * (cos(square_radians) + log(tan((square_radians) / 2)));
    p.y = length * sin(square_radians);
    return p;
}

double Tractrix::get_arc_length(double square) {
    return -1 * length * log(sin(square_radians));
}

double Tractrix::get_radius_of_curvature(double square){
    return length * (1 / tan(square_radians));
}

double Tractrix::get_area(double square){
    return (square_radians * pow(length, 2)) / 2;
}

double Tractrix::get_area_of_surface(double square){
    return 4 * square_radians * pow(length, 2);
}

double Tractrix::get_volume(double square){
    return (2.0 / 3.0) * square_radians * pow(length, 3);
}