// single source shortest path algorithm

struct dijkstra {
    const int inf = 1e9;
    int mx;
    vector<vector<array<int, 2>>> edges;
    vector<int> dist;

    dijkstra (int nodes, vector<vector<array<int, 2>>> adj) {
        mx = nodes + 5;
        edges = adj;
        dist.resize(mx, inf);
    }

    void shortest_path(int source) {
        set<array<int, 2>> s;
        s.insert({0, source});
        while(!s.empty()) {
            auto p = *s.begin();
            s.erase(s.begin());
            if (dist[p[1]] != inf) continue;
            dist[p[1]] = p[0];
            for(array<int, 2> adj: edges[p[1]]) {
                s.insert({dist[p[1]] + adj[1], adj[0]});
            }
        }
    }

    int get_dist(int source, int destination) {
        shortest_path(source);
        return dist[destination];
    }
};
