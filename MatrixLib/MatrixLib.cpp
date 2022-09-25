#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

double** createMatrix(size_t rows, size_t cols)
{
    double** matrix = new double* [rows];
    for (size_t idx = 0; idx < rows; ++idx)
        matrix[idx] = new double[cols];
    return matrix;
}

double** multMatrix(double lambda, double** M, size_t rows, size_t columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            M[i][j] *= lambda;
        }
    }
}

double** plusMatrix(double** A, double** B, size_t rows, size_t columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            A[i][j] += B[i][j];
        }
    }
}

double** minusMatrix(double** A, double** B, size_t rows, size_t columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            A[i][j] -= B[i][j];
        }
    }
}

double** multMatrix(double** A, double** B, double** C, size_t rowsA, size_t columnsA, size_t columnsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < columnsA; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < columnsB; ++k) {
                C[i][j] += B[k][j] * A[i][k];
            }
        }
    }
}

double& maximumMatrix(double** M, size_t rows, size_t columns) {
    double max = M[0][0];
    int a = 0, b = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (max < M[i][j]) {
                max = M[i][j];
                a = i;
                b = j;
            }
        }
    }
    return M[a][b];
}

void mixMatrix(double** M, size_t rows, size_t columns, size_t K_1, size_t K_2) {
    size_t tmp;
    for (int j = 0; j < columns; ++j) {
         tmp = M[K_1][j];
         M[K_1][j] = M[K_2][j];
         M[K_2][j] = tmp;
     }
    for (int i = 0; i < rows; ++i) {
        tmp = M[i][K_1];
        M[i][K_1] = M[i][K_2];
        M[i][K_2] = tmp;
    } 
}

void localMinimum(double** A, double value, size_t rows, size_t columns) {
    for (int r = 0; r < rows; r++)
    {
        double local_min = A[r][0];
        int c_min = 0;
        for (int c = 0; c < columns; c++)
        {
            if (local_min > A[r][c]) {
                local_min = A[r][c];
                c_min = c;
            }
        }
        A[r][c_min] = value;
    }
}

double det(double** M, size_t size) {
    if (size == 1)
        return M[0][0];

    double det_val = 0.0, sign = 1.0;
    for (int i = 0; i < size; ++i, sign *= -1.) {
        if (M[0][i] == 0)
            continue;
        double** M1 = new double* [size - 1];
        for (int j = 1; j < size; ++j) {
            M1[j - 1] = new double[size - 1];
            for (int c = 0, c_current = 0; c < size; ++c, ++c_current) {
                if (i == c) {
                    --c_current;
                    continue;
                }
                M1[j - 1][c_current] = M[j][c];
            }
        }
        det_val += sign * M[0][i] * det(M1, size - 1);
    }
    return det_val;
}

double** inv(double** M, size_t size) {
    double** inversive = new double* [size];
    double det_A = det(M, size);

    if (det_A == 0)
        return new double* [0];

    for (int i = 0; i < size; ++i) {
        inversive[i] = new double[i];
        for (int j = 0; j < size; ++j) {
            double** A_ij = new double* [size];
            for (int k = 0; k < size; ++k) {
                A_ij[k] = new double[size];
                for (int n = 0; n < size; ++n) {
                    if (k == i && n == j)
                        A_ij[k][n] = 1.0;
                    else if (k == i || n == j)
                        A_ij[k][n] = 0.0;
                    else
                        A_ij[k][n] = M[k][n];
                }
            }
            inversive[i][j] = det(A_ij, size) / det_A;
        }
    }
    return transpose(inversive, size, size);
}

void deleteMatrix(double** matrix, size_t rows, size_t cols)
{
    for (size_t idx = 0; idx < rows; ++idx)
        delete[] matrix[idx];
    delete[] matrix;
}

void inputMatrix(double** matrix, size_t rows, size_t cols)
{
    std::cout << "Input matrix with " << cols << " cols:\n";
    for (size_t r = 0; r < rows; ++r)
    {
        std::cout << "Input " << r << " row: ";
        for (size_t c = 0; c < cols; ++c)
            std::cin >> matrix[r][c];
    }
}

double** inputFileMatrix(char const* filename, size_t& rows, size_t& cols)
{
    std::ifstream in(filename);
    if (!in.is_open())
        throw std::runtime_error("Failed to open matrix file");
    in >> rows >> cols;
    double** matrix = createMatrix(rows, cols);
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            in >> matrix[r][c]; //*(*(matrix+r)+c)
    in.close();
    return matrix;
}

void printMatrix(double** matrix, size_t rows, size_t cols)
{
    for (size_t r = 0; r < rows; ++r)
    {
        for (size_t c = 0; c < cols; ++c)
            std::cout << matrix[r][c] << '\t';
        std::cout << '\n';
    }
    std::cout << '\n';
}

void zeros(double** matrix, size_t rows, size_t cols)
{
    fill(matrix, rows, cols, 0);
}

void ones(double** matrix, size_t rows, size_t cols)
{
    fill(matrix, rows, cols, 1);
}

void fill(double** matrix, size_t rows, size_t cols, double val)
{
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            matrix[r][c] = val;
}

double** linspace(size_t length)
{
    double** vec = createMatrix(1, length);
    for (size_t idx = 0; idx < length; ++idx)
        vec[0][idx] = idx + 1;
    return vec;
}

double** transpose(double** matrix, size_t rows, size_t cols)
{
    double** transposed = createMatrix(cols, rows);
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            transposed[c][r] = matrix[r][c];
    return transposed;
}

template <typename Type>
void Swap(Type& a, Type& b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}

void rotate180(double** matrix, size_t rows, size_t cols)
{
    // Step 1. reverse elements in each row
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols / 2; ++c)
            Swap(matrix[r][c], matrix[r][cols - c - 1]);

    ////Step 2. reverse rows
    for (size_t r = 0; r < rows / 2; ++r)
        Swap(matrix[r], matrix[rows - r - 1]);
}

double& findMinimum(double** matrix, size_t rows, size_t cols)
{
    double minimum = **matrix;
    size_t r_min = 0;
    size_t c_min = 0;
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            if (matrix[r][c] < minimum)
            {
                minimum = matrix[r][c];
                r_min = r;
                c_min = c;
            }
    return matrix[r_min][c_min];
}

double& minmaxMatrix(double** matrix, size_t rows, size_t cols)
{
    size_t r_min = 0;
    size_t c_min = 0;
    size_t r_max = 0;
    size_t c_max = 0;
    double minimum;
    double maximum;
    for (size_t r = 0; r < rows; ++r) {
        minimum = matrix[r][0];
        r_min = r;
        c_min = 0;
        for (size_t c = 1; c < cols; ++c)
            if (matrix[r][c] < minimum) {
                minimum = matrix[r][c];
                r_min = r;
                c_min = c;
            }
        if (r == 0 || minimum > maximum) {
            maximum = minimum;
            r_max = r_min;
            c_max = c_min;
        }
    }
    return matrix[r_max][c_max];
}

void mixMatrix(double** matrix,
    size_t rows,
    size_t cols,
    size_t k1,
    size_t k2)
{
    if (k1 == k2)
        return;
    if (k1 >= rows || k1 >= cols || k2 >= rows || k2 >= cols)
        return;
    Swap(matrix[k1], matrix[k2]);
    for (size_t r = 0; r < rows; ++r)
        Swap(matrix[r][k1], matrix[r][k2]);
}

void randMatrix(double** matrix,
    size_t rows,
    size_t cols,
    double minval,
    double maxval)
{
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            matrix[r][c] = ((maxval - minval) * rand()) / RAND_MAX + minval;
}
