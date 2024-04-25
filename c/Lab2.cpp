#include <iostream>
#include <cstring>
using namespace std;

class StringOperations {
private:
    char str[100];

public:
    void readString() {
        cout << "Enter a string: ";
        cin.getline(str, 100);
    }

    int getLength() {
        return strlen(str);
    }

    void concatenateSubstring() {
        char sub[100];
        cout << "Enter the substring to concatenate: ";
        cin.getline(sub, 100);
        strcat(str, sub);
        cout << "Concatenated string: " << str << endl;
    }

    int compareString() {
        char sub[100];
        cout << "Enter another string to compare: ";
        cin.getline(sub, 100);
        int result = strcmp(str, sub);
        cout << "Comparison result: " << result << endl;
        return result;
    }

    int searchCharacter(char ch) {
        int charPosition = -1;
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == ch) {
                charPosition = i;
                break;
            }
            i++;
        }
        if (charPosition != -1)
            cout << "Character found at position: " << charPosition << endl;
        else
            cout << "Character not found in the string." << endl;
        return charPosition;
    }

    int searchSubstring() {
        char sub[100];
        cout << "Enter the substring to search for in the string: ";
        cin.getline(sub, 100);
        int subPosition = -1;
        int i = 0;
        int j;
        while (str[i] != '\0') {
            j = 0;
            while (str[i + j] == sub[j]) {
                if (sub[j] == '\0') {
                    subPosition = i;
                    break;
                }
                j++;
            }
            if (sub[j] == '\0') {
                subPosition = i;
                break;
            }
            i++;
        }
        if (subPosition != -1)
            cout << "Substring found at position: " << subPosition << endl;
        else
            cout << "Substring not found in the string." << endl;
        return subPosition;
    }

    void tokenizeString() {
        char delimiter[100];
        cout << "Enter the delimiter: ";
        cin.getline(delimiter, 100);
        char* token;
        token = strtok(str, delimiter);
        while (token != nullptr) {
            cout << token << endl;
            token = strtok(nullptr, delimiter);
        }
    }

    void convertToUppercase() {
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            i++;
        }
        cout << "Uppercase string: " << str << endl;
    }

    void convertToLowercase() {
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            i++;
        }
        cout << "Lowercase string: " << str << endl;
    }
};

int main() {
    StringOperations strOps;

    strOps.readString();
    int length = strOps.getLength();
    cout << "Length of the string: " << length << endl;

    strOps.concatenateSubstring();

    int compareResult = strOps.compareString();

    char ch;
    cout << "Enter a character to search for in the string: ";
    cin >> ch;
    int charPosition = strOps.searchCharacter(ch);

    if (compareResult == 0 && charPosition == -1) {
        strOps.tokenizeString();
        strOps.convertToUppercase();
        strOps.convertToLowercase();
    }

    return 0;
}
