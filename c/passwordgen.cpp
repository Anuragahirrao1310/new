#include <iostream>
using namespace std;

int count = 0;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void generateCombinations(char* chars, int Index, int passwordLength, char* password, int start) {
    if (Index == passwordLength) {
        password[Index] = '\0';
        cout << password << endl;
        count++;
        return;
    }

    for (int i = start; chars[i] != '\0'; ++i) {
        password[Index] = chars[i];
        generateCombinations(chars, Index + 1, passwordLength, password, i + 1);
    }
}

void generatePermutations(char* chars, int Index, int passwordLength, char* password) {
    if (Index == passwordLength) {
        password[Index] = '\0';
        cout << password << endl;
        count++;
        return;
    }

    for (int i = Index; chars[i] != '\0'; ++i) {
        swap(chars[Index], chars[i]);
        password[Index] = chars[Index];
        generatePermutations(chars, Index + 1, passwordLength, password);
        swap(chars[Index], chars[i]);
    }
}

int main() {
    const int maxlength = 100;
    char characters[maxlength];
    char password[maxlength];
    int passwordLength = 0;
    int choice;

    cout << "Enter the characters to use for password generation: ";
    cin >> characters;

    cout << "Enter the password length: ";
    cin >> passwordLength;

    while (true) {
        cout << "\nChoose the option:\n";
        cout << "1. Generate Combinations\n";
        cout << "2. Generate Permutations\n";
        cout << "3. Exit\n";
        cin >> choice;

        cout << "\nGenerated Passwords:\n";
        count = 0;

        switch (choice) {
        case 1:
            generateCombinations(characters, 0, passwordLength, password, 0);
            break;
        case 2:
            generatePermutations(characters, 0, passwordLength, password);
            break;
        case 3:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please select either 1, 2, or 3." << endl;
            break;
        }

        cout << "Total passwords generated: " << count << endl;
    }

    return 0;
}
