#include <bits/stdc++.h>

void findMedian(int *arr, int n) {
    // Write your code here
    priority_queue <int, vector <int>> maxH;
    priority_queue <int, vector <int>, greater <int>> minH;

    for (int i=0; i<n; i++) {
        if (maxH.size()==0) {
            maxH.push (arr[i]);
            cout << arr[i] << " ";
            continue;
        }
        if (arr[i]>maxH.top()) {
            minH.push (arr[i]);
            if (minH.size()-maxH.size()>1) {
                maxH.push (minH.top());
                minH.pop();
            }
        }
        else {
            maxH.push (arr[i]);
            if (maxH.size()-minH.size()>1) {
                minH.push (maxH.top());
                maxH.pop();
            }
        }
        if (minH.size()==maxH.size()) cout << ((minH.top()+maxH.top())/2) << " ";
        else if (minH.size()>maxH.size()) cout << minH.top() << " ";
        else cout << maxH.top() << " ";
    }
}
