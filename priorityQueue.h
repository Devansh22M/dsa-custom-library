struct priorityQueue {
    int n;
    vector<int> heap;
    priorityQueue() {
        n = 0;
    }
    void insert(int x) {
        heap.push_back(x);
        ++n;
        int i = n - 1;
        while(i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    int remove_min() {
        swap(heap[0], heap[n - 1]);
        --n;
        int i = 0;
        while(2 * i + 1 < n) {
            int j = 2 * i + 1;
            if (2 * i + 2 < n && heap[2 * i + 2] < heap[j]) {
                j = 2 * i + 2;
            }
            if (heap[j] >= heap[i]) {
                break;
            }
            swap(heap[j], heap[i]);
            i = j;
        }
        return heap[n];
    }
    void heap_sort() {
        for(int i = n - 1; i >= 0; i--) {
            heap[i] = remove_min();
        }
        reverse(heap.begin(), heap.end());
        n = heap.size();
    }
    void display() {
        for(int i = 0; i < n; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};


