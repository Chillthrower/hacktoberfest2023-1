#include <iostream>
#define MAX 5 // Change the MAX value as needed
using namespace std;

struct CircularQueue {
    int front, rear;
    int data[MAX];

    CircularQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insert(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert " << value << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }

        data[rear] = value;
        cout << "Element inserted: " << value << endl;
    }

    int del() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete." << endl;
            return -1;
        }

        int value = data[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }

        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        if (front <= rear) {
            while (i <= rear) {
                cout << data[i] << " ";
                i++;
            }
        } else {
            while (i < MAX) {
                cout << data[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear) {
                cout << data[i] << " ";
                i++;
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue;

    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    queue.insert(40);
    queue.insert(50);
    
    queue.display();

    int deletedValue = queue.del();
    if (deletedValue != -1) {
        cout << "Deleted element: " << deletedValue << endl;
    }

    queue.display();

    queue.insert(60);
    queue.insert(70);

    queue.display();

    return 0;
}
