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
            // Linear probing to find the next available slot
            while(a[index] != -1) {
                index = (index + 1) % 10;
            }
            a[index] = key;
            count++;
        }
    }

    cout << "\nResultant hash table is: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << "\t" << i << ". " << a[i] << endl;
    }

    return 0;
}
