#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

// Function to rearrange the array as per the given pattern
void rearrangeArray(int arr[], int n) {
    // Sort the array in descending order
    sort(arr, arr + n, greater<int>());

    int result[n];
    int left = 0, right = n - 1;
    bool turn = true; // To control alternating sides

    for (int i = 0; i < n; i++) {
        if (turn) {
            result[i] = arr[left++];
        } else {
            result[i] = arr[right--];
        }
        turn = !turn; // Switch sides
    }

    // Print the rearranged array
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Rearranged Array: ";
    rearrangeArray(arr, n);

    return 0;
}
