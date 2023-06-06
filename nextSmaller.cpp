#include <stack>
#include <vector>
#include <climits>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
        vector<int> ans(n);
        s.push(INT_MAX);

        for(int i = n-1; i >= 0; i--){
            int curr = arr[i];
            
            while(!s.empty() && s.top() >= curr){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }
            s.push(curr);
        }

        return ans;
}
