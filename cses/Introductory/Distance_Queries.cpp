#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int LOG = 21;

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];

    for (int j = 0; j < LOG; j++) {
        if (diff & (1 << j)) {
            u = up[u][j];
        }
    }

    if (u == v) return u;

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    adj.assign(n + 1, vector<int>());
    up.assign(n + 1, vector<int>(LOG, 0));
    depth.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Iterative BFS to avoid recursion depth issues
    queue<int> qu;
    qu.push(1);
    up[1][0] = 0;
    depth[1] = 0;

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == up[u][0]) continue;

            up[v][0] = u;
            depth[v] = depth[u] + 1;
            qu.push(v);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        int x = lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[x] << '\n';
    }

    return 0;
}