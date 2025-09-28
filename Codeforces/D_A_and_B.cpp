#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <iomanip>
#include <utility>
using namespace std;

long long minCost(vector<int> &pos) {
    if (pos.empty()) return 0;
    vector<long long> q;
    for (int i = 0; i < (int)pos.size(); i++) {
        q.push_back(1LL * pos[i] - i);
    }
    nth_element(q.begin(), q.begin() + q.size() / 2, q.end());
    long long med = q[q.size() / 2];
    long long cost = 0;
    for (auto x : q) cost += llabs(x - med);
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> posA, posB;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') posA.push_back(i+1);
            else posB.push_back(i+1);
        }

        long long ans = min(minCost(posA), minCost(posB));
        cout << ans << "\n";
    }
}
