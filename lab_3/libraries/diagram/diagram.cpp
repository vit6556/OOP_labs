#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <algorithm>
#include <cstring>
#include "include/diagram.h"

using namespace diagram;

Diagram::~Diagram() {
    delete [] signals;
}

Diagram::Diagram() {
    signals = new signal[length];
    for (int i = 0; i < length; ++i)
        signals[i] = signal{};
}

Diagram::Diagram(int l, char value, int max_signal_length) {
    length = l;
    if (value != '0' && value != '1' && value != 'X')
        throw std::invalid_argument("Invalid signal value");

    signals = new signal[length];
    for (int i = 0; i < length; ++i)
        signals[i] = signal{value, max_signal_length};
}

Diagram::Diagram(int l, std::string values, int max_signal_length) {
    length = l;
    if (length != values.length())
        throw std::invalid_argument("Invalid diagram length");

    signals = new signal[length];
    for (int i = 0; i < length; ++i) {
        char v = values[i];
        if (v != '0' && v != '1' && v!= 'X')
            throw std::invalid_argument("Invalid signal value");

        signals[i] = signal{v, max_signal_length};
    }
}


void Diagram::copy(int amount) {
    int new_length = length * (amount + 1);
    signal *new_signals = new signal[new_length];

    for (int i = 0; i < new_length; ++i)
        new_signals[i] = signals[i % length];
    
    length = new_length;
    delete [] signals;
    signals = new_signals;
}

void Diagram::print() {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < signals[i].length; ++j)
            std::cout << signals[i].value;

        if (i < length - 1)
            std::cout << "|";
    }
    std::cout << "\n";
}

void Diagram::rotate_left(int amount) {
    amount = amount % length;
    for (int j = 0; j < amount; ++j) {
        signal tmp = signals[0];
        for (int i = 0; i < length - 1; ++i)
            signals[i] = signals[i + 1];
        signals[length - 1] = tmp;
    }
}

void Diagram::rotate_right(int amount) {
    amount = amount % length;
    for (int j = 0; j < amount; ++j) {
        signal tmp = signals[length - 1];
        for (int i = length - 1; i > 0; --i)
            signals[i] = signals[i - 1];
        signals[0] = tmp;
    }
}

void Diagram::update_signal(int index, char value, int length) {
    if (value != '0' && value != '1' && value != 'X')
        throw std::invalid_argument("Invalid signal value");

    signals[index].value = value;
    signals[index].length = length;
}

signal* Diagram::get_signals() {
    return signals;
}

int Diagram::get_length() {
    return length;
}

Diagram* Diagram::operator + (Diagram *d) {
    int new_length = d->get_length() + length;
    signal *new_signals = new signal[new_length + 1];

    signal *s = d->get_signals();
    memcpy(new_signals, signals, length * sizeof(signal));
    memcpy(&new_signals[length], s, d->get_length() * sizeof(signal));
    
    length = new_length;

    delete [] signals;
    signals = new_signals;

    return this;
}