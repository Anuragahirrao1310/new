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
        for (int i = 0; i < rows; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < columns; j++) {
                    cout << data[i][j] << " ";
                }
                cout<<endl;
            } else {
                for (int j = columns - 1; j >= 0; j--) {
                    cout << data[i][j] << " ";
                }
                cout<<endl;
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
    cout<<endl<<"Matrix in zigzag form :"<<endl;
    a.Zigzag();

    return 0;
}
