class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        
        // Build the adjacency list
        for (auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        // Min-heap for Dijkstra (travel_time, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // Start from node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue; // Skip outdated paths

            for (auto [neighbor, travel_time] : graph[node]) {
                long long new_time = time + travel_time;
                
                if (new_time < dist[neighbor]) { 
                    // Found a shorter path
                    dist[neighbor] = new_time;
                    ways[neighbor] = ways[node];
                    pq.push({new_time, neighbor});
                } 
                else if (new_time == dist[neighbor]) { 
                    // Found another way with the same shortest time
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};