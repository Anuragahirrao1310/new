#include <iostream>
using namespace std;

class MatrixRotator {
private:
    static const int MAX = 10;
    int matrix[MAX][MAX];
    int rows, cols;

public:
    MatrixRotator(int numRows, int numCols) : rows(numRows), cols(numCols) {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                 cout << "Enter element at position (" << i << ", " << j << "): ";
                 cin >> matrix[i][j];
            }
        }
    }

    void rotateClockwise() {
        int rotatedMatrix[MAX][MAX];

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                rotatedMatrix[j][rows - 1 - i] = matrix[i][j];
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = rotatedMatrix[i][j];
            }
        }
    }

    void printMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                 cout << matrix[i][j] << " ";
            }
             cout << "\n";
        }
    }
};

int main() {
    int numRows, numCols;

     cout << "Enter number of rows: ";
     cin >> numRows;

     cout << "Enter number of columns: ";
     cin >> numCols;

    MatrixRotator rotator(numRows, numCols);

     cout << "Original Matrix:\n";
    rotator.printMatrix();

    rotator.rotateClockwise();

     cout << "Matrix Rotated Clockwise:\n";
    rotator.printMatrix();

    return 0;
}
