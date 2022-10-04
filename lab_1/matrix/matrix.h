#ifndef LAB_1_MATRIX_H
#define LAB_1_MATRIX_H

#include <iostream>
#include <vector>

namespace matrix {
    struct Matrix {
        int m, n;
        std::vector<int> values;
        std::vector<int> columns;
        std::vector<int> rows;
    };

    Matrix input_matrix();
    void print_matrix(Matrix& matrix);
    int get_last_value_in_row(Matrix& matrix, int row);
}
#endif //LAB_1_MATRIX_H