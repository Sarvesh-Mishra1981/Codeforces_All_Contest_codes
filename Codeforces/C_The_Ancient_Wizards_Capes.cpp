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
#include<unordered_set>
#include<unistd.h>
#include<unordered_map>
using namespace std;
using ll = long long;
const ll MOD = 676767677LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> s(n+1);
        for (int i = 1; i <= n; ++i) s[i] = i - a[i];
        set<int> cand;
        int t1 = -s[1];
        int t2 = 1 - s[1];
        if (0 <= t1 && t1 <= n) cand.insert(t1);
        if (0 <= t2 && t2 <= n) cand.insert(t2);
        ll ans = 0;
        for (int t : cand) {
            int bprev = 0;
            bool ok = true;
            int sumx = 0;
            for (int i = 1; i <= n; ++i) {
                int ci = t + s[i];
                int xi = ci - 2 * bprev;
                if (!(xi == 0 || xi == 1)) { ok = false; break; }
                bprev += xi;
                sumx += xi;
                if (bprev < 0 || bprev > i) { ok = false; break; }
            }
            if (!ok) continue;
            if (bprev != t) continue;
            // valid arrangement for this t -> exactly one sequence x determined
            ans = (ans + 1) % MOD;
        }
        cout << ans % MOD << '\n';
    }
    return 0;
}