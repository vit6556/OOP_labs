#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "include/diagram.h"

using namespace diagram;

Diagram::Diagram() {
    for (int i = 0; i < 10; ++i)
        signals.push_back(signal{});
}

Diagram::Diagram(int length, char value, int max_signal_length) {
    if (value != '0' && value != '1' && value != 'X')
        throw std::runtime_error("Invalid signal value");

    for (int i = 0; i < length; ++i)
        signals.push_back(signal{value, max_signal_length});
}

Diagram::Diagram(int length, std::string values, int max_signal_length) {
    if (length != values.length())
        throw std::runtime_error("Invalid diagram length");

    for (int i = 0; i < length; ++i) {
        char v = values[i];
        if (v != '0' && v != '1' && v!= 'X')
            throw std::runtime_error("Invalid signal value");

        signals.push_back(signal{v, max_signal_length});
    }
}

Diagram::Diagram(int length, std::vector<signal> values) {
    signals = values;
}


void Diagram::copy(int amount) {
    int length = signals.size();
    int new_length = length * (amount + 1);
    signals.reserve(new_length);
    for (int i = 0; i < new_length - length; ++i)
        signals.push_back(signals[i]);
}

void Diagram::print() {
    for (int i = 0; i < signals.size(); ++i) {
        for (int j = 0; j < signals[i].length; ++j)
            std::cout << signals[i].value;

        if (i < signals.size() - 1)
            std::cout << "|";
    }
    std::cout << "\n";
}

void Diagram::rotate_left(int amount) {
    rotate(signals.begin(), signals.begin() + amount, signals.end());
}

void Diagram::rotate_right(int amount) {
    rotate(signals.rbegin(), signals.rbegin() + amount, signals.rend());
}

void Diagram::update_signal(int index, char value, int length) {
    if (value != '0' && value != '1' && value != 'X')
        throw std::runtime_error("Invalid signal value");

    signals[index].value = value;
    signals[index].length = length;
}

std::vector<signal> Diagram::get_signals() {
    return this->signals;
}

Diagram Diagram::operator + (Diagram d) {
    std::vector<signal> v;

    std::vector<signal> s1 = this->signals;
    std::vector<signal> s2 = d.get_signals();
    std::copy(s1.begin(), s1.end(), std::back_inserter(v));
    std::copy(s2.begin(), s2.end(), std::back_inserter(v));

    return Diagram(v.size(), v);
}