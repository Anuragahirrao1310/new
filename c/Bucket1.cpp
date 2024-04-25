#include <iostream>
using namespace std;

const int MAX_COMBINATIONS = 100;

void generateCombinations(int n, int k, int x, int current, int* currentCombination, int currentIndex) {
    if (currentIndex == k) {
        bool includeX = false;
        for (int i = 0; i < k; ++i) {
             cout << currentCombination[i] << " ";
            if (currentCombination[i] == x) {
                includeX = true;
            }
        }
        if (includeX) {
             cout << "(Including " << x << ")" <<  endl;
        } else {
             cout << "(Excluding " << x << ")" <<  endl;
        }
        return;
    }

    for (int i = current; i <= n; ++i) {
        currentCombination[currentIndex] = i;
        generateCombinations(n, k, x, i + 1, currentCombination, currentIndex + 1);
    }
}

void combinations(int n, int k, int x) {
    int currentCombination[MAX_COMBINATIONS];
    generateCombinations(n, k, x, 1, currentCombination, 0);
}

int main() {
    int n, k, x;
     cout << "Enter the value of n: ";
     cin >> n;
     cout << "Enter the number of selected objects (k): ";
     cin >> k;
     cout << "Enter the element to include in combinations: ";
     cin >> x;

     cout << "\nAll combinations of " << k << " numbers from the range 1 to " << n << " that include " << x << ":\n";
    combinations(n, k, x);

    return 0;
}