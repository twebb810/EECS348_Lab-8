#include "matrix.hpp"
#include <fstream>
#include <iostream>
#include <vector>

Matrix read_matrix(std::ifstream &in, size_t N) {
    std::vector<std::vector<int>> nums(N, std::vector<int>(N));
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            in >> nums[i][j];
    return Matrix(nums);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Failed to open file: " << argv[1] << "\n";
        return 1;
    }

    size_t N;
    infile >> N;
    Matrix A = read_matrix(infile, N);
    Matrix B = read_matrix(infile, N);

    std::cout << "Matrix A:\n";
    A.print_matrix();
    std::cout << "\nMatrix B:\n";
    B.print_matrix();

    std::cout << "\nA + B:\n";
    (A + B).print_matrix();

    std::cout << "\nA * B:\n";
    (A * B).print_matrix();

    std::cout << "\nSum of major diagonal in A: " << A.sum_diagonal_major() << "\n";
    std::cout << "Sum of minor diagonal in A: " << A.sum_diagonal_minor() << "\n";

    size_t r1, r2;
    std::cout << "\nEnter two row indices to swap in A: ";
    std::cin >> r1 >> r2;
    try {
        A.swap_rows(r1, r2);
        std::cout << "Matrix A after swapping rows:\n";
        A.print_matrix();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    size_t c1, c2;
    std::cout << "\nEnter two column indices to swap in A: ";
    std::cin >> c1 >> c2;
    try {
        A.swap_cols(c1, c2);
        std::cout << "Matrix A after swapping columns:\n";
        A.print_matrix();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    size_t row, col;
    int new_val;
    std::cout << "\nEnter row, column, and new value to update A: ";
    std::cin >> row >> col >> new_val;
    try {
        A.set_value(row, col, new_val);
        std::cout << "Matrix A after update:\n";
        A.print_matrix();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
