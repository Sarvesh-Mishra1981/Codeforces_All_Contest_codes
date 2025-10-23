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
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define in(v) for(auto &x:v) cin>>x
#define tc ll t;cin>>t;while(t--)

const ll MOD = 1e9+7;

void solve(vi& a, ll n) {
    map<ll, ll> m;
    fi(i, 0, n) m[a[i]]++;

    ll sum = 0, cnt = 0;
    vi v;

    for (auto x : m) {
        if (x.second & 1)
            v.push_back(x.first);
        
        sum += (x.second / 2) * 2 * x.first;
        cnt += (x.second / 2) * 2;
    }

    if (sum == 0) {
        cout << 0 << endl;
        return;
    }

    sort(v.begin(), v.end());
    ll finans = 0;

    for (ll val : v) {
        if (val < sum)
            finans = max(finans, sum + val);
    }

    for (ll i = 1; i < (ll)v.size(); i++) {
        if (v[i] - v[i - 1] < sum)
            finans = max(finans, sum + v[i] + v[i - 1]);
    }

    if (cnt > 2)
        finans = max(finans, sum);

    cout << finans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tc {
        ll n;
        cin >> n;
        vi v(n);
        in(v);
        solve(v, n);
    }
}
