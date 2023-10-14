#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int **data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void setData(int row, int col, int value) {
        data[row][col] = value;
    }

    int getData(int row, int col) const {
        return data[row][col];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    static Matrix subtract(const Matrix &A, const Matrix &B) {
        int rows = A.getRows();
        int cols = A.getCols();

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setData(i, j, A.getData(i, j) - B.getData(i, j));
            }
        }

        return result;
    }

    static Matrix multiply(const Matrix &A, const Matrix &B) {
        int rowsA = A.getRows();
        int colsA = A.getCols();
        int colsB = B.getCols();

        Matrix result(rowsA, colsB);
        for (int i = 0; i < rowsA; ++i) {
            for (int j = 0; j < colsB; ++j) {
                int sum = 0;
                for (int k = 0; k < colsA; ++k) {
                    sum += A.getData(i, k) * B.getData(k, j);
                }
                result.setData(i, j, sum);
            }
        }

        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix matrixA(3, 3);
    matrixA.setData(0, 0, 1);
    matrixA.setData(0, 1, 2);
    // ... Initialize the rest of matrixA

    Matrix matrixB(3, 3);
    matrixB.setData(0, 0, 9);
    matrixB.setData(0, 1, 8);
    // ... Initialize the rest of matrixB

    std::cout << "Matrix A:" << std::endl;
    matrixA.display();

    std::cout << "Matrix B:" << std::endl;
    matrixB.display();

    Matrix subtractionResult = Matrix::subtract(matrixA, matrixB);
    std::cout << "Matrix Subtraction:" << std::endl;
    subtractionResult.display();

    Matrix multiplicationResult = Matrix::multiply(matrixA, matrixB);
    std::cout << "Matrix Multiplication:" << std::endl;
    multiplicationResult.display();

    return 0;
}
