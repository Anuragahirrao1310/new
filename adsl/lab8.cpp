#include<iostream>
using namespace std;

int main() {
    int a[10];
    for(int i = 0; i < 10; i++) {
        a[i] = -1;
    }

    int count = 0;
    int n;

    while(true) {
        cout << "\nEnter 1 to insert an element and 0 to stop inserting: ";
        cin >> n;

        if(n == 0) break;

        if(count == 10) {
            cout << "Hash table is full. Cannot insert more elements." << endl;
            break;
        }

        int key;
        cout << "Enter Element: ";
        cin >> key;

        int index = key % 10;

        if(a[index] == -1) {
            a[index] = key;
            count++;
        } else {
            int originalIndex = index;
            bool replaced = false;
            // Linear probing to find the next available slot or replace an existing element
            while(true) {
                if(a[index] == -1) {
                    a[index] = key;
                    count++;
                    break;
                } else {
                    int temp = a[index];
                    a[index] = key;
                    key = temp;
                    replaced = true;
                }
                index = (index + 1) % 10;
                if(index == originalIndex) break; // Check if we have traversed the entire table
            }
            if(replaced) count++; // Increment count if an element is replaced
        }
    }

    cout << "\nResultant hash table is: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << "\t" << i << ". " << a[i] << endl;
    }

    return 0;
}
