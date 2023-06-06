#include <bits/stdc++.h> 
class Queue {
private:
    int *arr;
    int head;
    int tail;
    int currSize;

public:
    Queue() {
        // Implement the Constructor
        arr = new int [4];
        head = 0;
        tail = 0;
        currSize = 4;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (head==tail);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (tail==currSize) {
            int *newArr = new int [2*currSize];
            for (int i=0; i<currSize; i++) {
                newArr [i] = arr[i];
            }
            currSize = 2*currSize;
            delete arr;
            arr = newArr;
            arr[tail++] = data;
        }
        else {
            arr[tail++] = data;
        }

    }

    int dequeue() {
        // Implement the dequeue() function
        if (head==tail) return -1;
        return arr[head++];
    }

    int front() {
        // Implement the front() function
        if (head==tail) return -1;
        return arr[head];
    }
};
