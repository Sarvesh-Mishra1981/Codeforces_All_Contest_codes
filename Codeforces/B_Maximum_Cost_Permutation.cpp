#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> zeros; 
    vector<int> missing; 
    vector<bool> used(n + 1, false);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == 0) {
            zeros.push_back(i);
        } else {
            used[p[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            missing.push_back(i);
        }
    }
    sort(missing.begin(), missing.end());
    int max_cost = 0;
    vector<int> perm = p; 
    for (int i = 0; i < zeros.size(); i++) {
        perm[zeros[zeros.size() - 1 - i]] = missing[i];
    }
    int l = n, r = -1;
    for (int i = 0; i < n; i++) {
        if (perm[i] != i + 1) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    if (r >= l) {
        max_cost = max(max_cost, r - l + 1);
    }
    for (int i = 0; i < zeros.size(); i++) {
        perm[zeros[zeros.size() - 1 - i]] = missing[missing.size() - 1 - i];
    }
    l = n, r = -1;
    for (int i = 0; i < n; i++) {
        if (perm[i] != i + 1) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    if (r >= l) {
        max_cost = max(max_cost, r - l + 1);
    }
    
    cout << max_cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}