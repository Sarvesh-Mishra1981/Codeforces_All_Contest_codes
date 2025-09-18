#include <iostream>
#include<vector>

using namespace std;

long long solve(vector<vector<int>>& a, int n, int m) {
    long long ans = 0;
    int prev_time = 0;
    int prev_side = 0;  
    for (int i = 0; i < n; i++) {
        long long l = a[i][0] - prev_time;
        int required_parity = a[i][1] ^ prev_side;
        long long seg_max = l;
        if ((l % 2) != required_parity) {
            seg_max--;
        }
        ans += seg_max;
        prev_time = a[i][0];
        prev_side = a[i][1];
    }
    long long last_l = (long long)m - prev_time;
    ans += last_l;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        cout << solve(a, n, m) << endl;
    }
    return 0;
}