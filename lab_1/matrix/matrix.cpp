#include <iostream>
#include <vector>
#include "matrix.h"

namespace matrix {
    Matrix input_matrix() {
        Matrix matrix;
        std::cout << "Enter amount of rows: ";
        std::cin >> matrix.m;
        std::cout << "Enter amount of columns: ";
        std::cin >> matrix.n;

        int val;
        std::cout << "Enter matrix:\n";
        for (int i = 0; i < matrix.m; ++i) {
            for (int j = 0; j < matrix.n; ++j) {
                std::cin >> val;
                if (val != 0) {
                    matrix.values.push_back(val);
                    matrix.columns.push_back(j);
                    matrix.rows.push_back(i);
                }
            }
        }

        return matrix;
    }

    void print_matrix(Matrix& matrix) {
        int item_id = 0;

        for(int r = 0; r < matrix.m; ++r) {
            for(int c = 0; c < matrix.n; ++c) {
                if(item_id < matrix.values.size() && matrix.rows[item_id] == r && matrix.columns[item_id] == c) {
                    std::cout << matrix.values[item_id] << " ";
                    item_id += 1;
                } else {
                    std::cout << 0 << " ";
                }
            }
            std::cout << "\n";
        }
    }

    int get_last_value_in_row(Matrix& matrix, int row) {
        int current_last_value = 0;
        for (int i = 0; i < matrix.rows.size(); ++i) {
            if (matrix.rows[i] == row) {
                current_last_value = matrix.values[i];
            } else if (matrix.rows[i] > row) {
                break;
            }
        }

        return current_last_value;
    }
}