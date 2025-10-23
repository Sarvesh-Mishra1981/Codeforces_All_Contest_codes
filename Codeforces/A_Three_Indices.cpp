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
#define ll long long
#define vi vector<ll>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tc ll t;cin>>t;while(t--)

// Helper function to find previous smaller element for each position
vector<ll> solve2(vi& a, ll n) {
    stack<ll> s;
    vector<ll> v(n);
    s.push(a[0]);
    v[0] = -1;

    for (ll i = 1; i < n; i++) {
        while (!s.empty() && s.top() > a[i]) {
            s.pop();
        }
        v[i] = s.empty() ? -1 : s.top();
        s.push(a[i]);
    }
    return v;
}

void solve(vi& a, ll n) {
    vi ans1 = solve2(a, n);

    reverse(a.begin(), a.end());
    vi ans2 = solve2(a, n);
    reverse(ans2.begin(), ans2.end());
    reverse(a.begin(), a.end());

    ll idx = -1;
    for (ll i = 0; i < n; i++) {
        if (ans1[i] != -1 && ans2[i] != -1) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
        cout << ans1[idx] << " " << a[idx] << " " << ans2[idx] << "\n";
    }
}

int main() {
    fast;
    tc {
        ll n; cin >> n;
        vi v(n); 
        for (auto &x : v) cin >> x;
        solve(v, n);
    }
}
