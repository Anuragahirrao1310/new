#include <iostream>

class ArraySorter {
private:
    int *arr;
    int size;

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    ArraySorter(int size) {
        this->size = size;
        arr = new int[size];
    }

    ~ArraySorter() {
        delete[] arr;
    }

    void inputArray() {
        std::cout << "Enter " << size << " elements of the array:" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    void bubbleSort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void selectionSort() {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    void insertionSort() {
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    ArraySorter sorter(size);

    sorter.inputArray();

    int choice;
    std::cout << "Choose sorting algorithm:" << std::endl;
    std::cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1:
            sorter.bubbleSort();
            break;
        case 2:
            sorter.selectionSort();
            break;
        case 3:
            sorter.insertionSort();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            return 1;
    }

    std::cout << "Sorted array: ";
    sorter.printArray();

    return 0;
}
