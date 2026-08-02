// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void transposeMatrix(int matrix[10][10], int rows, int cols);
void addMatrices(int matrixA[10][10], int matrixB[10][10], int rows, int cols);
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10],
                      int rowsA, int colsA, int rowsB, int colsB);

int main() {

    int matrix[10][10];
    int rows, cols;

    cout << "PART A - Transpose a Matrix" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }

    transposeMatrix(matrix, rows, cols);


    int matrixA[10][10];
    int matrixB[10][10];

    cout << "\n\nPART B - Add Two Matrices" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter elements for Matrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    cout << "\nEnter elements for Matrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element B[" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrixA[i][j];
        }
        cout << endl;
    }

    cout << "\nMatrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrixB[i][j];
        }
        cout << endl;
    }

    addMatrices(matrixA, matrixB, rows, cols);

    int A[10][10];
    int B[10][10];

    int rowsA, colsA, rowsB, colsB;

    cout << "\n\nPART C - Multiply Two Matrices" << endl;

    cout << "Enter number of rows for Matrix A: ";
    cin >> rowsA;

    cout << "Enter number of columns for Matrix A: ";
    cin >> colsA;

    cout << "Enter number of rows for Matrix B: ";
    cin >> rowsB;

    cout << "Enter number of columns for Matrix B: ";
    cin >> colsB;

    // Check multiplication condition
    if (colsA != rowsB) {
        cout << "\nMatrix multiplication is not possible." << endl;
        cout << "The columns of Matrix A must equal the rows of Matrix B."
             << endl;
        return 0;
    }

    cout << "\nEnter elements for Matrix A:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "\nEnter elements for Matrix B:\n";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << "Enter element B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }

    cout << "\nMatrix B:\n";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << setw(5) << B[i][j];
        }
        cout << endl;
    }

    multiplyMatrices(A, B, rowsA, colsA, rowsB, colsB);

    return 0;
}

void transposeMatrix(int matrix[10][10], int rows, int cols) {
    cout << "\nTransposed Matrix:\n";

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void addMatrices(int matrixA[10][10], int matrixB[10][10],
                 int rows, int cols) {

    int sum[10][10];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nSum of Matrix A and Matrix B:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << sum[i][j];
        }
        cout << endl;
    }
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10],
                      int rowsA, int colsA, int rowsB, int colsB) {

    int product[10][10] = {0};

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nProduct of Matrix A x Matrix B:\n";

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << setw(5) << product[i][j];
        }
        cout << endl;
    }
}

