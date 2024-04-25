#include <iostream>
#include <cstring>
using namespace std;

class StringOperations {
private:
    string str;

public:
    StringOperations(const string& s) {
        str = s;
    }

    void calculateFrequency() {
        int frequency[256] = {0};
        int len = str.length();

        for (int i = 0; i < len; i++) {
            frequency[(unsigned char)str[i]]++;
        }

        for (int i = 0; i < 256; i++) {
            if (frequency[i] > 0) {
                cout << "Frequency of '" << char(i) << "': " << frequency[i] << endl;
            }
        }
    }

    void deleteCharacter(char ch) {
        int len = str.length();
        int destIndex = 0;

        for (int i = 0; i < len; i++) {
            if (str[i] != ch) {
                str[destIndex] = str[i];
                destIndex++;
            }
        }
        str.resize(destIndex);
    }

    bool isPalindrome() {
        int len = str.length();
        int left = 0;
        int right = len - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    void displayString() {
        cout << "String: " << str << endl;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    StringOperations stringOps(input);

    int ch;
    cout << endl << "Choose the operation you want to perform on the string:\n"
         << "1. Calculate Frequency\n"
         << "2. Delete Character\n"
         << "3. Check Palindrome\n"
         << "Enter your choice (1-3): ";
    cin >> ch;

    switch (ch) {
        case 1:
            stringOps.calculateFrequency();
            break;
        case 2:
            char charToDelete;
            cout << "Enter the character you want to delete: ";
            cin >> charToDelete;
            stringOps.deleteCharacter(charToDelete);
            stringOps.displayString();
            break;
        case 3:
            if (stringOps.isPalindrome()) {
                cout << "The string is a palindrome." << endl;
            } else {
                cout << "The string is not a palindrome." << endl;
            }
            break;
        default:
            cout << endl << "Enter a valid choice (1-3)." << endl;
    }

    return 0;
}
