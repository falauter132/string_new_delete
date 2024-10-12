#include <iostream>

using namespace std;

void deleteRow(int** matrix, int& rows, int rowIndex) {
    if (rowIndex >= 0 && rowIndex < rows) {
        delete[] matrix[rowIndex];
        for (int i = rowIndex; i < rows - 1; ++i) {
            matrix[i] = matrix[i + 1];
        }
        rows--;
    }
    else {
        cout << "Неправильний індекс рядка" << endl;
    }
}

int main() {
    int rows = 3;
    int cols = 3;
    int** matrix = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    int rowToDelete = 1;
    deleteRow(matrix, rows, rowToDelete);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}