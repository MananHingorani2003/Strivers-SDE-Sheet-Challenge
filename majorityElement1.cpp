#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int element = 0;
	int count = 0;
	
	for (int i=0; i<n; i++) {
		if (count == 0) {
			element = arr [i];
			count++;
			continue;
		}
		if (element == arr[i]) count++;
		else count--;
	}

	int th = floor (n/2);
	int counter = 0;
	for (int i=0; i<n; i++) {
		if (element == arr[i]) counter++;
	}
	if (counter > th) return element;
	return -1;
}
