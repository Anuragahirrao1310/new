#include <iostream>

class ArraySorter {
private:
    int *arr;
    int size;

    void binaryInsertionSort() {
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int left = 0;
            int right = i - 1;

           
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] > key) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            
            for (int j = i - 1; j >= left; j--) {
                arr[j + 1] = arr[j];
            }

            
            arr[left] = key;
        }
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

    void sortUsingBinaryInsertion() {
        binaryInsertionSort();
    }
};

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    ArraySorter sorter(size);

    sorter.inputArray();

    sorter.sortUsingBinaryInsertion();

    std::cout << "Sorted array using Binary Insertion Sort: ";
    sorter.printArray();

    return 0;
}
