#include <bits/stdc++.h> 
void subsetSum2 (vector <int> &arr, int N, vector <int> &final, int sum, int index) {
        if (index==N) {
            final.push_back (sum);
            return;
        }
        subsetSum2 (arr, N, final, sum+arr[index], index+1);
        subsetSum2 (arr, N, final, sum, index+1);
    }

vector<int> subsetSum(vector<int> &num) {
    // Write your code here.
    vector <int> final;
    int n = num.size();
    int sum = 0;
    int index = 0;
    subsetSum2 (num, n, final, sum, index);
    sort(final.begin(), final.end());
        
    return final;
}
