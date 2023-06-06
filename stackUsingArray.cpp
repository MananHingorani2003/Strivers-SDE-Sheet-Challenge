#include <bits/stdc++.h> 
// Stack class.
class Stack {
private:
    int* arr;
    int tail;
    int max_size;
    
public:  
    Stack(int capacity) {
        // Write your code here.
        arr = new int [capacity];
        tail = 0;
        max_size = capacity;

    }

    void push(int num) {
        // Write your code here.
        if (tail == max_size) return;
        arr [tail++] = num; 
    }

    int pop() {
        // Write your code here.
        if (tail == 0) return -1;
        int num = arr [tail-1];
        tail--;
        return num;
    }
    
    int top() {
        // Write your code here.
        if (tail == 0) return -1;
        return arr [tail-1];
    }
    
    int isEmpty() {
        // Write your code here.
        return (tail==0);
    }
    
    int isFull() {
        // Write your code here.
        return (tail==max_size);
    }
    
};
