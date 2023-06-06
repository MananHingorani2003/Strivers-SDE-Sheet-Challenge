#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector <int> final;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i=0; i<n; i++) {
		int number = arr [i];
		if (maxHeap.size()==0) {
			maxHeap.push (number);
			final.push_back (number);
			continue;
		}
		if (number < maxHeap.top()) {
			maxHeap.push (number);
			if (maxHeap.size()-minHeap.size()>1) {
				minHeap.push (maxHeap.top());
				maxHeap.pop();
			}
		}
		else {
			minHeap.push (number);
			if (minHeap.size()-maxHeap.size()>1) {
				maxHeap.push (minHeap.top());
				minHeap.pop();
			}
		}
		if (minHeap.size()==maxHeap.size()) final.push_back ((minHeap.top()+maxHeap.top())/2);
		else if (minHeap.size() > maxHeap.size()) final.push_back(minHeap.top());
		else final.push_back (maxHeap.top());

	}

	return final;

}
