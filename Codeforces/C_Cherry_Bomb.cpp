#include <iostream>
#include<vector>
using namespace std;

int findmini(vector<int>& a) {
    int mini = INT_MAX;
    for (int v : a) mini = min(mini, v);
    return mini;
}

int findmax(vector<int>& a) {
    int maxi = INT_MIN;
    for (int v : a) maxi = max(maxi, v);
    return maxi;
}

long long solve(vector<int>& a, vector<int>& b, int k, int s) {
    int n = a.size();
    if (s == n) {
        int maxi = findmax(a);
        int mini = findmini(a);
        long long ans = 1LL * (k + mini - maxi + 1);
        return max(0LL, ans);
    }
    int target = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            target = a[i] + b[i];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            if (a[i] + b[i] != target) return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            int val = target - a[i];
            if (val < 0 || val > k) return 0;
        }
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        int numMissing = 0;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] == -1) numMissing++;
        }

        cout << solve(a, b, k, numMissing) << "\n";
    }
    return 0;
}
