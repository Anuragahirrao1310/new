#include <iostream>
using namespace std ;
const int MAX_SIZE = 100;
void largeno()
{

}
int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows, cols, max=0;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the elements of the first matrix:\n";
    for ( int i = 0 ; i < rows; i++) {
        for ( int j = 0; j < cols; j++) {
            std::cin >> mat1[i][j];
        }
    }


  return 0;
}
