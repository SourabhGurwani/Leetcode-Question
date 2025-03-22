class Solution {
public:
void dfs(int node, vector<vector<int>>& adj, unordered_set<int>& visited, vector<int>& component) {
    visited.insert(node);
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited.count(neighbor)) {
            dfs(neighbor, adj, visited, component);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
            // Step 1: Build adjacency list
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    unordered_set<int> visited;
    int completeComponents = 0;

    // Step 2: Find connected components using DFS
    for (int i = 0; i < n; ++i) {
        if (!visited.count(i)) {
            vector<int> component;
            dfs(i, adj, visited, component);

            // Step 3: Check if the component is complete
            int k = component.size();
            int expectedEdges = (k * (k - 1)) / 2;
            int actualEdges = 0;

            for (int node : component) {
                actualEdges += adj[node].size();
            }
            actualEdges /= 2; // Each edge is counted twice

            if (actualEdges == expectedEdges) {
                completeComponents++;
            }
        }
    }
    
    return completeComponents;
    }
};