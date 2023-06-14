#include <bits/stdc++.h> 
static bool comp (pair<int, int> &p1, pair<int, int> &p2) {
    return ((double)p1.second/p1.first) > ((double)p2.second/p2.first);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    double val = 0;
    sort (items.begin(), items.end(), comp);
    for (int i=0; i<n; i++) {
        if (w>=items[i].first) {
            val += items[i].second;
            w -= items[i].first;
        }
        else {
            val += double((double)items[i].second*w)/items[i].first;
            break;
        }
    }

    return val;

}
