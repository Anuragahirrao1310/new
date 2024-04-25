#include <iostream>
using namespace std;
class Matrix {
private:
    static const int MAX_ROWS = 100;
    static const int MAX_COLUMNS = 100;
    int rows;
    int columns;
    int data[MAX_ROWS][MAX_COLUMNS];
public:
    Matrix(int r, int c) : rows(r), columns(c) {}

    void readMatrix() {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << "Enter element at row " << i << ", column " << j << ": ";
                cin >> data[i][j];
            }
        }
    }
    void printMatrix() {
        cout << "The matrix is:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    int saddle() {
    for (int i = 0; i < rows; i++) {
        int minRowValue = data[i][0];
        int minColIndex = 0;

        for (int j = 1; j < columns; j++) {
            if (data[i][j] < minRowValue) {
                minRowValue = data[i][j];
                minColIndex = j;
            }
        }
        int saddlePoint = 1;

        for (int k = 0; k < rows; k++) {
            if (data[k][minColIndex] > minRowValue) {
                saddlePoint = 0; 
                break;
            }
        }
        if (saddlePoint == 1) {
            cout << "Saddle point is " << minRowValue <<endl;
            return minRowValue;
        }
    }
    cout << "No saddle point" <<endl;
    return -1;
}
};
int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
    Matrix mat(rows, columns);
    mat.readMatrix();
    mat.printMatrix();
    int saddlepoint = mat.saddle();
    cout << "The saddle point in the matrix is: " << saddlepoint << endl;
    return 0;
}
