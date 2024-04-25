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

    Matrix add(Matrix m2) {
        if (rows != m2.rows || cols != m2.cols) {
            cout << "Matrix addition not possible. Dimensions do not match." << endl;
            exit(1);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + m2.data[i][j];
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
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    Matrix m1(rows, cols), m2(rows, cols);
    cout << "For the first matrix:\n";
    m1.inputMatrix();
    cout << "For the second matrix:\n";
    m2.inputMatrix();

    cout << "First matrix:\n";
    m1.displayMatrix();
    cout << "Second matrix:\n";
    m2.displayMatrix();

    Matrix result = m1.add(m2);
    cout << "Resultant matrix:\n";
    result.displayMatrix();

    return 0;
}
