#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    void inputMatrix() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void displayMatrix() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix multiply(Matrix m2) {
        if (cols != m2.rows) {
            cout << "Matrix multiplication not possible. Invalid dimensions." << endl;
            exit(1);
        }

        Matrix result(rows, m2.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * m2.data[k][j];
                }
            }
        }
        return result;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    int rows1, cols1, rows2, cols2;
    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> rows1 >> cols1;
    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible. Invalid dimensions." << endl;
        return 1;
    }

    Matrix m1(rows1, cols1), m2(rows2, cols2);
    cout << "For the first matrix:\n";
    m1.inputMatrix();
    cout << "For the second matrix:\n";
    m2.inputMatrix();

    cout << "First matrix:\n";
    m1.displayMatrix();
    cout << "Second matrix:\n";
    m2.displayMatrix();

    Matrix result = m1.multiply(m2);
    cout << "Resultant matrix:\n";
    result.displayMatrix();

    return 0;
}
