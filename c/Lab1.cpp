#include <iostream>
#include <string>
using namespace std;

class CombinationGenerator {
private:
    char* arr;
    int len;

public:
    CombinationGenerator(int length) : len(length) {
        arr = new char[len];
    }

    ~CombinationGenerator() {
        delete[] arr;
    }

    void readArray() {
        cout << "Enter the numbers for the array:" << endl;
        for (int i = 0; i < len; i++) {
            cout << "Enter element " << i << ": ";
            cin >> arr[i];
        }
    }

    void generate(int i, string s) {
        if (i == 0) {
            cout << s << "\n";
            return;
        }

        for (int j = 0; j < len; j++) {
            string appended = s + arr[j];
            generate(i - 1, appended);
        }
    }

    void generateCombinations() {
        for (int i = 1; i <= len; i++) {
            generate(i, "");
        }
    }
};

int main() {
    int len;
    cout << "Enter the array length: ";
    cin >> len;

    CombinationGenerator combGen(len);
    combGen.readArray();
    combGen.generateCombinations();

    return 0;
}
