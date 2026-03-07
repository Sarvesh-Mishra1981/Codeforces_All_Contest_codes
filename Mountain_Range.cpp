#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Segment Tree for Range Maximum Query
struct SegTree {
    int n;
    vector<int> tree;
    
    SegTree(int n) {
        this->n = n;
        tree.assign(4 * n + 1, 0);
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }
};

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> L(n, -1), R(n, n);
    vector<int> st;

    // 1. Find the nearest mountain >= to the left using a monotonic stack
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.back()] < h[i]) {
            st.pop_back();
        }
        if (!st.empty()) L[i] = st.back();
        st.push_back(i);
    }

    st.clear();
    
    // 2. Find the nearest mountain >= to the right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.back()] < h[i]) {
            st.pop_back();
        }
        if (!st.empty()) R[i] = st.back();
        st.push_back(i);
    }

    // 3. Group indices by their mountain heights
    map<int, vector<int>> height_groups;
    for (int i = 0; i < n; i++) {
        height_groups[h[i]].push_back(i);
    }

    SegTree seg(n);
    int max_mountains = 1;
    vector<int> dp(n, 1);

    // 4. Process from shortest to tallest
    for (auto const& [height, indices] : height_groups) {
        
        // Step A: Query DP values for all mountains of the current height
        // We do this before updating the tree so mountains of the same height
        // don't accidentally treat each other as valid landing spots.
        for (int i : indices) {
            int left_bound = L[i] + 1;
            int right_bound = R[i] - 1;
            
            int max_jumps = 0;
            if (left_bound <= right_bound) {
                max_jumps = seg.query(1, 0, n - 1, left_bound, right_bound);
            }
            dp[i] = max_jumps + 1;
            max_mountains = max(max_mountains, dp[i]);
        }
        
        // Step B: Update the Segment tree with our newly calculated DP values
        for (int i : indices) {
            seg.update(1, 0, n - 1, i, dp[i]);
        }
    }

    cout << max_mountains << "\n";
    return 0;
}