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

const int SIZE = 10;

// Display matrix
void displayMatrix(int matrix[SIZE][SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose matrix
void transposeMatrix(int matrix[SIZE][SIZE], int transpose[SIZE][SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Part B: Add two matrices
void addMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Part C: Multiply two matrices
void multiplyMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE],
                      int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int A[SIZE][SIZE], B[SIZE][SIZE];
    int result[SIZE][SIZE];
    int transpose[SIZE][SIZE];

    int rows, cols;

    // Part A
    cout << "PART A: TRANSPOSE MATRIX" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter elements:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(A, rows, cols);

    transposeMatrix(A, transpose, rows, cols);

    cout << "\nTranspose Matrix:" << endl;
    displayMatrix(transpose, cols, rows);


    // Part B
    cout << "\nPART B: MATRIX ADDITION" << endl;

    cout << "Enter rows: ";
    cin >> rows;

    cout << "Enter columns: ";
    cin >> cols;

    cout << "Enter first matrix:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter second matrix:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> B[i][j];
        }
    }

    addMatrices(A, B, result, rows, cols);

    cout << "Sum Matrix:" << endl;
    displayMatrix(result, rows, cols);


    // Part C
    int rowsA, colsA, rowsB, colsB;

    cout << "\nPART C: MATRIX MULTIPLICATION" << endl;

    cout << "Enter rows of A: ";
    cin >> rowsA;

    cout << "Enter columns of A: ";
    cin >> colsA;

    cout << "Enter rows of B: ";
    cin >> rowsB;

    cout << "Enter columns of B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication not possible." << endl;
        return 0;
    }

    cout << "Enter matrix A:" << endl;

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix B:" << endl;

    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cin >> B[i][j];
        }
    }

    multiplyMatrices(A, B, result, rowsA, colsA, colsB);

    cout << "Product Matrix:" << endl;
    displayMatrix(result, rowsA, colsB);

    return 0;
}