#include <iostream>
#include <algorithm>

class Search {
private:
    int* arr;
    int size;

public:
    Search(int* a, int s) : arr(a), size(s) {}

    int linearSearch(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                return i; 
            }
        }
        return -1; 
    }
    int sentinelLinearSearch(int key) {
        int lastElement = arr[size - 1];
        arr[size - 1] = key; 
        int i = 0;
        while (arr[i] != key) {
            i++;
        }
        arr[size - 1] = lastElement; // Restore the last element
        if (i < size - 1 || arr[size - 1] == key) {
            return i; 
        }
        return -1; 
    }

   
    int binarySearch(int key) {
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) {
                return mid; 
            } else if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; 
    }
};

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int key = 23;
    int size = sizeof(arr) / sizeof(arr[0]);

    Search search(arr, size);

   
    int linearResult = search.linearSearch(key);
    if (linearResult != -1) {
        std::cout << "Linear Search: Element " << key << " found at index " << linearResult << std::endl;
    } else {
        std::cout << "Linear Search: Element " << key << " not found." << std::endl;
    }

    int sentinelResult = search.sentinelLinearSearch(key);
    if (sentinelResult != -1) {
        std::cout << "Sentinel Linear Search: Element " << key << " found at index " << sentinelResult << std::endl;
    } else {
        std::cout << "Sentinel Linear Search: Element " << key << " not found." << std::endl;
    }
    std::sort(arr, arr + size); // Binary search requires a sorted array
    int binaryResult = search.binarySearch(key);
    if (binaryResult != -1) {
        std::cout << "Binary Search: Element " << key << " found at index " << binaryResult << std::endl;
    } else {
        std::cout << "Binary Search: Element " << key << " not found." << std::endl;
    }

    return 0;
}
