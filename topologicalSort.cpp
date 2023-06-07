#include <bits/stdc++.h> 
void dfs (vector <bool> &visited, vector <int> &final2, vector <int> adj [], int index) {
    visited [index] = true;

    for (auto it: adj[index]) {
        if (!visited [it]) {
            dfs (visited, final2, adj, it);
        }
    }

    final2.push_back (index);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector <bool> visited (v+1, false);
    vector <int> adj [v];
    vector <int> final2;
    for (auto it: edges) {
        adj [it[0]].push_back (it[1]);
    }
    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            dfs (visited, final2, adj, i);
        }
    }
    reverse (final2.begin(), final2.end());
    return final2;

}
