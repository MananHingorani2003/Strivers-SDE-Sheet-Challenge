#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector <int> final2;
    stack<pair<int,int>>st;
    int i=1;

    for (int j=0; j<price.size(); j++) {
        int ans =0;
        while(!st.empty() and st.top().first<=price[j])
            st.pop();
        
        if(st.empty())
            ans = i;
        else
        {
            ans = i - st.top().second; 
        }
        
        st.push({price[j],i});
        i+=1;
        final2.push_back (ans);

    }

    return final2;
}
