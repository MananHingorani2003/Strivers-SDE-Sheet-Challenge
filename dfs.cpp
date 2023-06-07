void dfs (int index, vector <bool> &visited, vector<int> adj[], vector <int> &final2) {
    if (visited[index]) return;
    visited [index] = true;
    final2.push_back (index);
    for (auto it: adj[index]) {
        if (!visited[it]) {
            dfs (it, visited, adj, final2);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj [V];
    for (auto it: edges) {
        adj[it[0]].push_back (it[1]);
        adj[it[1]].push_back (it[0]);
    }
    vector <vector <int>> result;
    vector <bool> visited (V);
    for (int i=0; i<V; i++) visited [i] = false;

    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            vector <int> final2;
            dfs (i, visited, adj, final2);
            result.push_back (final2);
        }
    }
    
    return result;
}
