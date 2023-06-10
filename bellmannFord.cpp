#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector <int> distance (n+1, 1e9);
    distance [src] = 0;

    for (int i=0; i<n-1; i++) {
        for (auto it: edges) {
            if (distance[it[0]]!=1e9 && distance [it[0]]+it[2]<distance[it[1]]) {
                distance [it[1]] = distance [it[0]]+it[2];
            }
        }
    }

    bool flag = 0;
    for (auto it: edges) {
        if (distance[it[0]]!=1e9 && distance [it[0]]+it[2]<distance[it[1]]) {
            flag = 1;
        }
    }
    if (flag == 1) return -1;
    return distance [dest];
}
