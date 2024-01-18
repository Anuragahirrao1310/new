#include <iostream>
#include <queue>

class IntegerQueue {
private:
    std::queue<int> elements;

public:
    void enqueue(int num) {
        elements.push(num);
    }

    int dequeue() {
        if (elements.empty()) {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return 0; // You can choose to handle this differently
        }
        int frontElement = elements.front();
        elements.pop();
        return frontElement;
    }

    int getSum() {
        int sum = 0;
        std::queue<int> copy = elements;
        while (!copy.empty()) {
            sum += copy.front();
            copy.pop();
        }
        return sum;
    }

    bool isEmpty() {
        return elements.empty();
    }
};

int main() {
    IntegerQueue myQueue;
    
    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(20);

    int sum = myQueue.getSum();
    std::cout << "Sum of elements in the queue: " << sum << std::endl;

    while (!myQueue.isEmpty()) {
        int frontElement = myQueue.dequeue();
        std::cout << "Dequeued: " << frontElement << std::endl;
    }

    return 0;
}
