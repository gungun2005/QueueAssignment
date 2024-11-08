#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int *queue;
    int front, rear, size;

public:
    // Constructor to initialize the queue with a specific size
    ArrayQueue(int s) {
        size = s;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~ArrayQueue() {
        delete[] queue;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == size - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Insert an element into the queue (Enqueue operation)
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
        } else {
            if (front == -1) front = 0; // Initialize front on first enqueue
            queue[++rear] = data;
            cout << "Inserted " << data << " into queue." << endl;
        }
    }

    // Remove an element from the queue (Dequeue operation)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Deleted " << queue[front++] << " from queue." << endl;
            if (front > rear) front = rear = -1; // Reset queue if empty
        }
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    ArrayQueue q(size);

    // Example operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}
