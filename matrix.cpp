#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

Matrix::Matrix(size_t N) : size(N), data(N, std::vector<int>(N, 0)) {}

Matrix::Matrix(std::vector<std::vector<int>> nums)
    : size(nums.size()), data(std::move(nums)) {}

Matrix Matrix::operator+(const Matrix &rhs) const {
    if (size != rhs.size) throw std::invalid_argument("Matrix sizes do not match for addition");
    Matrix result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + rhs.data[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    if (size != rhs.size) throw std::invalid_argument("Matrix sizes do not match for multiplication");
    Matrix result(size);
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            for (size_t k = 0; k < size; ++k)
                result.data[i][j] += data[i][k] * rhs.data[k][j];
    return result;
}

void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= size || j >= size) throw std::out_of_range("Index out of bounds");
    data[i][j] = n;
}

int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= size || j >= size) throw std::out_of_range("Index out of bounds");
    return data[i][j];
}

int Matrix::get_size() const {
    return size;
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += data[i][i];
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += data[i][size - i - 1];
    return sum;
}

void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= size || r2 >= size) throw std::out_of_range("Invalid row index");
    std::swap(data[r1], data[r2]);
}

void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= size || c2 >= size) throw std::out_of_range("Invalid column index");
    for (size_t i = 0; i < size; ++i)
        std::swap(data[i][c1], data[i][c2]);
}

void Matrix::print_matrix() const {
    for (const auto &row : data) {
        for (int val : row)
            std::cout << std::setw(4) << val;
        std::cout << '\n';
    }
}
