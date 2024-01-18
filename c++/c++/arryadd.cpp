#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

class ArrayMultiplier {
private:
    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];
    int result[MAX_SIZE];
    int n;

public:
    void getInput() {
        cout << "Enter the size of the Array: ";
        cin >> n;

        cout << "Enter the elements of the first array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        cout << "Enter the elements of the second array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
    }

    void multiplyArrays() {
        for (int i = 0; i < n; i++) {
            result[i] = arr1[i] * arr2[i];
        }
    }

    void displayResult() {
        cout << "Resultant array after multiplication: ";
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayMultiplier arrayMultiplier;
    arrayMultiplier.getInput();
    arrayMultiplier.multiplyArrays();
    arrayMultiplier.displayResult();

    return 0;
}
