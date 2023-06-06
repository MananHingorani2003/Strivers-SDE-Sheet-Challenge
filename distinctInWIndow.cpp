#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector <int> final;
    unordered_map <int, int> mahi;
    int n = arr.size();
    int i = 0;
    int j = 0;

    while (j<n) {
        mahi [arr[j]]++;
        if (j-i+1 < k) j++;
        else if (j-i+1 == k) {
            final.push_back (mahi.size());
            mahi [arr[i]]--;
            if (mahi[arr[i]]==0) mahi.erase (arr[i]);
            j++;
            i++;
        }
    }

    return final;
	
}
