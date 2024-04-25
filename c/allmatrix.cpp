#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[r];
        for (int i = 0; i < r; ++i) {
            data[i] = new int[c];
        }
    }

    void inputMatrix() {
        std::cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    void displayMatrix() {
        std::cout << "Matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix add(Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix subtract(Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix& other) {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix divide(int divisor) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] / divisor;
            }
        }
        return result;
    }
};

int main() {
    int rows1, cols1, rows2, cols2;
    std::cout << "Enter the number of rows and columns for the first matrix: ";
    std::cin >> rows1 >> cols1;
    std::cout << "Enter the number of rows and columns for the second matrix: ";
    std::cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        std::cout << "Matrix dimensions don't match for multiplication. Exiting program.\n";
        return 1;
    }

    Matrix matrix1(rows1, cols1);
    Matrix matrix2(rows2, cols2);

    std::cout << "For the first matrix:\n";
    matrix1.inputMatrix();
    std::cout << "For the second matrix:\n";
    matrix2.inputMatrix();

    int choice;
    std::cout << "Choose operation: 1 (Addition), 2 (Subtraction), 3 (Multiplication), 4 (Division): ";
    std::cin >> choice;

    Matrix result(rows1, cols2);

    switch (choice) {
        case 1:
            if (rows1 == rows2 && cols1 == cols2) {
                result = matrix1.add(matrix2);
                result.displayMatrix();
            } else {
                std::cout << "Matrix dimensions don't match for addition. Exiting program.\n";
                return 1;
            }
            break;
        case 2:
            if (rows1 == rows2 && cols1 == cols2) {
                result = matrix1.subtract(matrix2);
                result.displayMatrix();
            } else {
                std::cout << "Matrix dimensions don't match for subtraction. Exiting program.\n";
                return 1;
            }
            break;
        case 3:
            result = matrix1.multiply(matrix2);
            result.displayMatrix();
            break;
        case 4:
            int divisor;
            std::cout << "Enter the divisor for division: ";
            std::cin >> divisor;
            result = matrix1.divide(divisor);
            result.displayMatrix();
            break;
        default:
            std::cout << "Invalid choice. Exiting program.\n";
            return 1;
    }

    return 0;
}
