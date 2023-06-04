#include <bits/stdc++.h> 

void merge (vector <int> &nums, int low, int mid, int high) {
        int left = low;
        int right = mid+1;
        vector <int> temp;

        while (left <= mid && right <= high) {
            if (nums[left]<=nums[right]) {
                temp.push_back (nums[left]);
                left++;
            }
            else {
                temp.push_back (nums[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back (nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back (nums[right]);
            right++;
        }
        for (int i=low; i<=high; i++) {
            nums [i] = temp [i-low];
        }
    }

    void mergeSort (vector <int> &nums, int low, int high, int &count) {
        if (low >= high) return;
        int mid = (low+high)/2;
        mergeSort (nums, low, mid, count);
        mergeSort (nums, mid+1, high, count);
        int left = low;
        int right = mid+1;

        for (int i=low; i<=mid; i++) {
            while (right <= high && static_cast<long long>(nums[i]) > 2 * static_cast<long long>(nums[right])) {
                right++;
            }
            count = count + (right-(mid+1));
        }

        merge (nums, low, mid, high);
    }


int reversePairs(vector<int> &nums, int n){
	// Write your code here.	
	int count = 0;
    mergeSort (nums, 0, n-1, count);

    return count;
}
