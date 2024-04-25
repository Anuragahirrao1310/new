#include <iostream>
#include <cstring>
using namespace std;

// Function to calculate the frequency of characters in the string
void calculateFrequency(const string& str) {
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

// Function to delete a specific character from the string
void deleteCharacter(string& str, char ch) {
    int len = str.length();
    int destIndex = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != ch) {
            str[destIndex] = str[i];
            destIndex++;
        }
    }
    str[destIndex] = '\0';
}

// Function to check if the string is a palindrome
bool isPalindrome(const string& str) {
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

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int ch;
    cout << endl << "Choose the operation you want to perform on the string:\n"
         << "1. Frequency\n"
         << "2. Delete\n"
         << "3. Char Delete\n"
         << "4. Palindrome\n"
         << "Enter your choice: ";
    cin >> ch;

    switch (ch) {
        case 1:
            calculateFrequency(input);
            break;
        case 2:
            char charToDelete;
            cout << "Enter the character you want to delete: ";
            cin >> charToDelete;
            deleteCharacter(input, charToDelete);
            cout << "String after deleting '" << charToDelete << "': " << input << endl;
            break;
        case 3:
            // Add code for the Char Delete operation
            break;
        case 4:
            if (isPalindrome(input)) {
                cout << "The string is a palindrome." << endl;
            } else {
                cout << "The string is not a palindrome." << endl;
            }
            break;
        default:
            cout << endl << "Enter a valid choice." << endl;
    }

    return 0;
}
