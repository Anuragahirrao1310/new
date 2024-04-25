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
    void checkmatrix(){
        if(rows==columns){
            cout<<endl<<"It is a square matrix";
        }
        else
        cout<<endl<<"It is not a square matrix";
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
    mat.checkmatrix();
    return 0;
}