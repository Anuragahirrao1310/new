#include <iostream>

using namespace std;

class MatrixMirror {
private:
    static const int MAX = 10;
    int matrix[MAX][MAX];
    int size;

public:
    MatrixMirror(int matrixSize) : size(matrixSize) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << "Enter element at position (" << i << ", " << j << "): ";
                cin >> matrix[i][j];
            }
        }
    }

    void mirrorAcrossDiagonal() {
        int mirroredMatrix[MAX][MAX];

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                mirroredMatrix[i][j] = matrix[size - 1 - i][size - 1 - j];
            }
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = mirroredMatrix[i][j];
            }
        }
    }

    void printMatrix() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int matrixSize;

    cout << "Enter size of the matrix: ";
    cin >> matrixSize;

    MatrixMirror mirror(matrixSize);

    cout << "Original Matrix:\n";
    mirror.printMatrix();

    mirror.mirrorAcrossDiagonal();

    cout << "Matrix Mirror Across Diagonal:\n";
    mirror.printMatrix();

    return 0;
}
