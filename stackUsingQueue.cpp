#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int>q1,q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q1.size()==0)
        return 1;

        return 0;
    }

    void push(int x) {
        // Implement the push() function.
        q1.push(x);
    }

    int pop() {
        // Implement the pop() function.
        if (q1.size()==0) return -1;
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }

    int top() {
        // Implement the top() function.
        if (q1.size()==0) return -1;
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q1.pop();
        q2.push(ans);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
};
