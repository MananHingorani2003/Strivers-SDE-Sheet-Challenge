#include <bits/stdc++.h>

bool bfs(vector<int> adj[], vector<bool>& visited, int index) {
    queue<pair<int, int>> mahi;
    mahi.push({index, -1});
    visited[index] = true;

    while (!mahi.empty()) {
        int node = mahi.front().first;
        int parent = mahi.front().second;
        mahi.pop();

        for (auto it : adj[node]) {
            if (!visited[it]) {
                mahi.push({it, node});
                visited[it] = true;
            } else {
                if (parent != it) return true;
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    vector<int> adj[n + 1];
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (bfs(adj, visited, i)) return "Yes";
        }
    }

    return "No";
}
