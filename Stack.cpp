// Siddharth Bansal - 032

#include <iostream>
#include <vector>
#include <stdexcept>

class Stack {
private:
    std::vector<int> items;

public:
    Stack() {} // Default constructor

    bool isEmpty() const {
        return items.empty();
    }

    void push(int item) {
        items.push_back(item);
        std::cout << "Pushed: " << item << ". Stack now: [";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << items[i] << (i == items.size() - 1 ? "" : ", ");
        }
        std::cout << "]\n";
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty. Cannot pop.\n";
            throw std::out_of_range("pop from empty stack");
        }
        int popped_item = items.back();
        items.pop_back();
        std::cout << "Popped: " << popped_item << ". Stack now: [";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << items[i] << (i == items.size() - 1 ? "" : ", ");
        }
        std::cout << "]\n";
        return popped_item;
    }

    int peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty. No item to peek.\n";
            throw std::out_of_range("peek from empty stack");
        }
        return items.back();
    }

    size_t size() const {
        return items.size();
    }
};

int main() {
    Stack myStack;

    std::cout << "\n--- Initializing Stack ---\n";
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Stack size: " << myStack.size() << "\n";

    std::cout << "\n--- Pushing elements ---\n";
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    std::cout << "\n--- After pushing ---\n";
    std::cout << "Top element (peek): " << myStack.peek() << "\n";
    std::cout << "Stack size: " << myStack.size() << "\n";

    std::cout << "\n--- Popping elements ---\n";
    try {
        myStack.pop();
        myStack.pop();
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught an error during pop: " << e.what() << "\n";
    }

    std::cout << "\n--- After popping ---\n";
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Stack size: " << myStack.size() << "\n";

    std::cout << "\n--- Attempting to pop from an empty stack ---\n";
    try {
        myStack.pop();
        myStack.pop();
        myStack.pop();
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught expected error: " << e.what() << "\n";
    }

    std::cout << "\n--- Final Stack State ---\n";
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Stack size: " << myStack.size() << "\n";

    return 0;
}
    