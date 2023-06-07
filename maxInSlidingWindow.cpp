#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    int i = 0;
        int j = 0;    
        int n = nums.size();
        deque <int> q;
        vector <int> ans;

        while (j<n) {
            int num = nums [j];
            while (!q.empty() && num > q.back()) {
                q.pop_back();
            }
            q.push_back (num);
            if (j-i+1<k) j++;
            else {
                ans.push_back (q.front());
                if (q.front()==nums[i]) q.pop_front();
                j++;
                i++;
            }
        }

        return ans;
}
