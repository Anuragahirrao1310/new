#include<iostream>
using namespace std ;
const int MAX_SIZE = 100;

void multiplyArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    for (int i = 0; i < n1; i++) {
        result[i] = arr1[i] * arr2[i];
    }
}

int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int result[MAX_SIZE];
    int n ;
    
    cout<<"enter the size of the Arry :";
    cin>>n;

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr1[i];
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr2[i];
    }

    multiplyArrays(arr1, n, arr2, n, result);

    cout << "Resultant array after multiplication: ";
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
