#include <iostream>

using namespace std;

void generateCombinations(int n, int k, int start, int* current, int currentIndex) {
    if (k == 0) {
        for (int i = 0; i < currentIndex; ++i) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; ++i) {
        current[currentIndex] = i;
        generateCombinations(n, k - 1, i + 1, current, currentIndex + 1);
    }
}

void combinations(int n, int k) {
    int* current = new int[k];
    generateCombinations(n, k, 1, current, 0);
    delete[] current;
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << "\nAll combinations of " << k << " numbers chosen from the range 1 to " << n << ":\n";
    combinations(n, k);

 return 0;
}