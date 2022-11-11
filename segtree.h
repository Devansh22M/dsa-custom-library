// segment tree data structure for range queries

#define sz(x) (int)x.size()

struct item {
    int s;
};

struct segtree {
    int size;
    vector<item> values;
    // merge(X, NEUTRAL_ELEMENT) = X
    item NEUTRAL_ELEMENT;

    void init(int n) {
        size = 1;
        // size should be power of 2 to get a symmetric segment tree 
        while(size < n) size *= 2;
        values.resize(2 * size);
    }

    // handle leaf nodes
    item single(int v) {
        return {v};
    }

    // associative function definition
    item merge(item a, item b) {
        return {a.s + b.s};
    }

    // building segment tree from given array in O(n)
    void build(vector<int> &arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            // we are on a leaf node
            if (lx < sz(arr)) {
                values[x] = single(arr[lx]);
            }
            return;
        }

        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector<int> &arr) {
        build(arr, 0, 0, size);
    }
    
    // set or update value at index i in arr
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = single(v);
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    item range_query(int l, int r, int x, int lx, int rx) {
        // no overlap
        if (lx >= r || l >= rx) {
            return NEUTRAL_ELEMENT;
        }
        // full overlap
        if (lx >= l && rx <= r) {
            return values[x];
        }
        // partial overlap

        int m = (lx + rx) / 2;
        item a = range_query(l, r, 2 * x + 1, lx, m);
        item b = range_query(l, r, 2 * x + 2, m, rx);

        item res = merge(a, b);
        return res;
    }

    item range_query(int l, int r) {
        return range_query(l, r, 0, 0, size);
    }
};
