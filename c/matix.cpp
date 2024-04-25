#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        // Allocate memory for the matrix
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Destructor to free allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Getters and setters
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        } else {
            cout << "Error: Invalid index!\n";
        }
    }

    int getValue(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        } else {
            cout << "Error: Invalid index!\n";
            return -1; // Return some default value or handle the error accordingly
        }
    }
};

int main() {
    int numRows, numCols;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    Matrix myMatrix(numRows, numCols);

    // Input values for the matrix
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            int value;
            cin >> value;
            myMatrix.setValue(i, j, value);
        }
    }

    // Display the matrix
    cout << "The matrix is:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << myMatrix.getValue(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
