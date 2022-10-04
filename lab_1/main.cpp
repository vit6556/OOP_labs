#include <iostream>
#include <vector>
#include "matrix/matrix.h"

using namespace matrix;

int get_sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main() {
    Matrix matrix = input_matrix();
    Matrix new_matrix = matrix;

    for (int i = 0; i < new_matrix.rows.size(); ++i) {
        int last_value = get_last_value_in_row(new_matrix, new_matrix.rows[i]);
        if (get_sum_of_digits(new_matrix.values[i]) != get_sum_of_digits(last_value)) {
            new_matrix.values[i] = 0;
        }
    } 
    
    std::cout << "\nOriginal matrix:\n";
    print_matrix(matrix);
    std::cout << "\nNew matrix:\n";
    print_matrix(new_matrix);
}

// 12 5 3 0 0
// 0 4 13 4 4
// 0 0 9 5 9
// 1 2 3 4 5
// 0 5 6 24 0