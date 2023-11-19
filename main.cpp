#include <iostream>

#include <iostream>
#include <cassert>
#include "matrix.h"

int main() {

    Matrix<int, -1> matrix;
    assert(matrix.size() == 0); // все ячейки свободны
    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);
    matrix[100][101] = 415;
    matrix[101][101] = 515;
    matrix[99][99] = 999;
    matrix[99][99] = -1;

    ((matrix[100][100] = 314) = 0) = 217;

    for(auto& [xy, v]: matrix)
    {
        std::cout << xy.first << xy.second << v << std::endl;
    }
    std::cout << std::endl;


    int maxN = 10;
    Matrix<int, 0> matrix2;
    for (int i = 0; i < maxN; ++i)
    {
        matrix2[i][i] = i;
        matrix2[maxN - 1 - i][i] = i;
    }

    for (int i = 1; i < maxN - 1; ++i)
    {
        for (int j = 1; j < maxN - 1; ++j)
            std::cout << matrix2[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << "Number of filled cells: " << matrix2.size() << std::endl;

    for(auto& [xy, v]: matrix2)
    {
        std::cout << "Row: " << xy.first << " Col: "  << xy.second << " Val: "  << v << std::endl;
    }
}
