struct floyd_warshall {
    int INF = 1e9;
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> dist;

    floyd_warshall(int nodes, vector<vector<int>> edges) {
        adj = edges;
        n = nodes;
        dist.resize(n + 5, vector<int> (n + 5));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = INF;
                if (i == j) {
                    dist[i][j] = 0;
                }
            }
        }
        for(int u = 1; u <= n; u++) {
            for(int v: edges[u]) {
                dist[u][v] = 1;
            }
        }
    }

    void shortest_dist() {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
                }
            }
        }
    }

    int get_dist(int u, int v) {
        return dist[u][v];
    }
};
