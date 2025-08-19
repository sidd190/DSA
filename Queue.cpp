// Siddharth Bansal - 032

#include <iostream>
#include <vector>
#include <stdexcept>

class Queue {
private:
    std::vector<int> items;

public:
    Queue() {} // Default constructor

    bool isEmpty() const {
        return items.empty();
    }

    // Add an element to the back of the queue
    void enqueue(int item) {
        items.push_back(item);
        std::cout << "Enqueued: " << item << ". Queue now: [";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << items[i] << (i == items.size() - 1 ? "" : ", ");
        }
        std::cout << "]\n";
    }

    // Remove and return the element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Error: Queue is empty. Cannot dequeue.\n";
            throw std::out_of_range("dequeue from empty queue");
        }
        int dequeued_item = items.front(); // Get the first element (front of queue)
        items.erase(items.begin());       // Remove the first element
        std::cout << "Dequeued: " << dequeued_item << ". Queue now: [";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << items[i] << (i == items.size() - 1 ? "" : ", ");
        }
        std::cout << "]\n";
        return dequeued_item;
    }

    // Get the front element without removing it
    int front() const {
        if (isEmpty()) {
            std::cerr << "Error: Queue is empty. No item at front.\n";
            throw std::out_of_range("front from empty queue");
        }
        return items.front();
    }

    // Get the current number of elements in the queue
    size_t size() const {
        return items.size();
    }
};

int main() {
    Queue myQueue;

    std::cout << "\n--- Initializing Queue ---\n";
    std::cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Queue size: " << myQueue.size() << "\n";

    std::cout << "\n--- Enqueueing elements ---\n";
    myQueue.enqueue(100);
    myQueue.enqueue(200);
    myQueue.enqueue(300);
    myQueue.enqueue(400);

    std::cout << "\n--- After enqueueing ---\n";
    std::cout << "Front element: " << myQueue.front() << "\n";
    std::cout << "Queue size: " << myQueue.size() << "\n";

    std::cout << "\n--- Dequeueing elements ---\n";
    try {
        myQueue.dequeue();
        myQueue.dequeue();
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught an error during dequeue: " << e.what() << "\n";
    }

    std::cout << "\n--- After dequeueing ---\n";
    std::cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Queue size: " << myQueue.size() << "\n";

    std::cout << "\n--- Attempting to dequeue from an empty queue ---\n";
    try {
        myQueue.dequeue(); // Dequeue remaining element (300)
        myQueue.dequeue(); // Dequeue remaining element (400)
        myQueue.dequeue(); // Attempt to dequeue from an empty queue
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught expected error: " << e.what() << "\n";
    }

    std::cout << "\n--- Final Queue State ---\n";
    std::cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Queue size: " << myQueue.size() << "\n";

    return 0;
}
