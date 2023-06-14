#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector <int> final2;
    priority_queue <pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

    for (int i=0; i<k; i++) pq.push ({kArrays[i][0], {i, 0}});

    while (!pq.empty()) {
        int topElement = pq.top().first;
        int whichArray = pq.top().second.first;
        int index = pq.top().second.second;
        pq.pop();

        final2.push_back (topElement);
        int sizeofArray = kArrays[whichArray].size();
        if (index+1<sizeofArray)
            pq.push ({kArrays[whichArray][index+1], {whichArray, index+1}});
    }

    return final2;
}
