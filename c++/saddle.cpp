#include <iostream>
#include <climits>

class Matrix {
private:
    int **data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int *[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    void inputMatrix() {
        std::cout << "Enter the elements of the matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    void printMatrix() {
        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void findSaddlePoint() {
      for (int i = 0; i < rows; ++i) {
            int saddleValue = INT_MAX;
            int saddleCol = -1;

            // Find the minimum value in the current row
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] < saddleValue) {
                    saddleValue = data[i][j];
                    saddleCol = j;
                }
            }

            // Check if the saddle value is also the maximum value in its column
            bool isSaddlePoint = true;
            for (int k = 0; k < rows; ++k) {
                if (data[k][saddleCol] > saddleValue) {
                    isSaddlePoint = false;
                    break;
                }
            }

            if (isSaddlePoint) {
                std::cout << "Saddle point found at position (" << i << ", " << saddleCol << "): " << saddleValue << std::endl;
            }
             if (isSaddlePoint= false ) {
                std::cout << "There is noSaddle point found "<< std::endl;
            }
            
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows and columns in the matrix: ";
    std::cin >> rows >> cols;

    Matrix matrix(rows, cols);
    matrix.inputMatrix();

    matrix.printMatrix(); // Print the entered matrix
    matrix.findSaddlePoint();

    return 0;
}
