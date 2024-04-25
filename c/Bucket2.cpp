#include <iostream>
#include <string>
using namespace std;

class StringChecker {
private:
    string str;

public:
    StringChecker(const string& s) {
        str = s;
    }

    void checkDuplicates() {
        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j < str.length(); j++) {
                if (str[i] == str[j]) {
                    cout << "The string has duplicate characters." << endl;
                    return;
                }
            }
        }
        cout << "The string does not have any duplicate characters." << endl;
    }
};

int main() {
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr);

    StringChecker stringChecker(inputStr);
    stringChecker.checkDuplicates();

    return 0;
}
