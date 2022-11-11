// implementation of disjoin set union data structure

struct dsu {
    int mx = 1e5 + 5;
    int p[mx], sz[mx];
    
    void make_set(int x) {
        p[x] = x;
        sz[x] = 1;
    }

    int find_set(int x) {
        if (x == p[x]) return x;
        return find_set(parent[x]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
