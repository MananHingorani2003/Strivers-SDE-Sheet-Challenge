#include <bits/stdc++.h> 
void helper (vector <vector <int>> &final, vector <int> &temp, vector <int> &nums, int start) {
        final.push_back (temp);

        for (int i=start; i<nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            temp.push_back (nums[i]);
            helper (final, temp, nums, i+1);
            temp.pop_back ();
        }
    }
vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
{
    // Write your code here.
    sort (nums.begin (), nums.end());
        vector <vector <int>> final;
        vector <int> temp;

        helper (final, temp, nums, 0);
        return final;
}
