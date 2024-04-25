#include <iostream>
#include <string>
using namespace std;

class StringOperations {
private:
    string str;

public:
    StringOperations(const string& inputStr) : str(inputStr) {}

    void calculateFrequency(char ch) {
        int count = 0;
        for (char c : str) {
            if (c == ch) {
                count++;
            }
        }
        cout << "The number of times the character was repeated: " << count << endl;
    }

    void eraseString() {
        str.erase();
        cout << "After erase(): " << str << endl;
    }

    void deleteCharacter(int index) {
        if (index >= 0 && index < str.length()) {
            str.erase(index, 1);
            cout << "After deleteCharacter(): " << str << endl;
        } else {
            cout << "Invalid index. No character deleted." << endl;
        }
    }

    string checkPalindrome() {
        int len = str.length();
        int left = 0;
        int right = len - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return "not";
            }
            left++;
            right--;
        }

        return "is";
    }
};

int main() {
    string inputStr;
    cout << "Enter a string: ";
    getline(cin, inputStr);

    StringOperations strOps(inputStr);

    int choice;
    cout << "Choose the option given below:\n";
    cout << "1. Frequency\n";
    cout << "2. Erase\n";
    cout << "3. Delete a character\n";
    cout << "4. Check Palindrome\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
        {
            char ch;
            cout << "Enter the required character: ";
            cin >> ch;
            strOps.calculateFrequency(ch);
            break;
        }
        case 2:
            strOps.eraseString();
            break;
        case 3:
        {
            int index;
            cout << "Enter the index to delete character: ";
            cin >> index;
            strOps.deleteCharacter(index);
            break;
        }
        case 4:
            if (strOps.checkPalindrome() == "is") {
                cout << "The string is a palindrome." << endl;
            } else {
                cout << "The string is not a palindrome." << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
s