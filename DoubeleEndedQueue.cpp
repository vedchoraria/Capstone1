#include <iostream>
#define MAX 100
using namespace std;

class Deque {
    public:
    int arr[MAX];
    int front, rear;
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is full." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }

        arr[front] = x;
        cout << x << " inserted at front." << endl;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is full." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } 
        else {
            rear++;
        }

        arr[rear] = x;
        cout << x << " inserted at rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << arr[front] << " deleted from front." << endl;

        if (front == rear) {
            front = rear = -1; // Deque becomes empty
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << arr[rear] << " deleted from rear." << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements are: ";
        int i = front;
        for(i; i!=rear;i=(i+1)%MAX) {
            cout << arr[i] << " ";
        }
        cout<<arr[i]<<" "; // Print the last element
        cout << endl;
    }
};

// Driver Code
int main() {
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);
    dq.display();

    dq.deleteFront();
    dq.display();

    dq.deleteRear();
    dq.display();

    dq.insertRear(100);
    dq.display();

    return 0;
}
