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

    void input() {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << "Enter element at row " << i << ", column " << j << ": ";
                cin >> data[i][j];
            }
        }
    }

    void print() {
        cout << "The matrix is:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    void Zigzag() {
        for (int diag = 0; diag < rows + columns - 1; diag++) {
            if (diag % 2 == 0) {
                for (int i = 0; i <= diag; i++) {
                    int j = diag - i;
                    if (i < rows && j < columns) {
                        cout << data[i][j] << " ";
                    }
                }
            }
            else {
                for (int j = 0; j <= diag; j++) {
                    int i = diag - j;
                    if (i < rows && j < columns) {
                        cout << data[i][j] << " ";
                    }
                }
            }
        }
    }
};

int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    Matrix a(rows, columns);
    a.input();
    a.print();
    
    cout << endl << "Matrix in zigzag form:" << endl;
    a.Zigzag();

    return 0;
}
