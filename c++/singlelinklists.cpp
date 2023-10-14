#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

   
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList myList;

    int value;
    std::cout << "Enter a value for the first node: ";
    std::cin >> value;
    myList.insertAtBeginning(value);

    char choice;
    do {
        std::cout << "Do you want to enter another value? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            std::cout << "Enter a value for the next node: ";
            std::cin >> value;
            myList.insertAtBeginning(value);
        }
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Linked List: ";
    myList.display();

    return 0;
}
