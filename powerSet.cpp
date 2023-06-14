#include <bits/stdc++.h> 
void subsets2 (vector <int> &nums, int index, vector <vector <int>> &final, vector <int> &m) {
        int n = nums.size();
        if (index==n) {
            final.push_back (m);
            return;
        }
        m.push_back (nums[index]);
        subsets2 (nums, index+1, final, m);
        m.pop_back ();
        subsets2 (nums, index+1, final, m);
    }

    vector<vector<int>> pwset(vector<int>& nums) {
        vector <vector <int>> final;
        vector <int> m;
        int index = 0;
        subsets2 (nums, index, final, m);

        return final;
    }
