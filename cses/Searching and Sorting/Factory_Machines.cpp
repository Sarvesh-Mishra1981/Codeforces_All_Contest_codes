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

// -----------------------------------Lets Do IT---------------------------------------------------------------
#define ll __int128_t
#define vi vector<ll>
#define all(x) (x).begin(), (x).end()
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define in(v) for(auto &x:v) read128(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void read128(__int128 &x) {
    string s;
    cin >> s;
    x = 0;
    int sign = 1;
    int i = 0;
    if (s[0] == '-') {
        sign = -1;
        i = 1;
    }
    for (; i < (int)s.size(); i++)
        x = x * 10 + (s[i] - '0');
    x *= sign;
}

void print128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

bool check(vi &a, ll n, ll mid, ll k) {
    ll cnt = 0;
    fi(i, 0, n) {
        cnt += mid / a[(long long)i];
    }
    return cnt >= k;
}

ll solve(vi &a, ll k, ll n) {
    ll st = 1;
    ll ed = 1000000000000000000LL;
    ll ans = ed;

    while (st <= ed) {
        ll mid = st + (ed - st) / 2;

        if (check(a, n, mid, k)) {
            ans = mid;
            ed = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    fast;

    ll n, k;
    read128(n);
    read128(k);

    vi a((long long)n);
    in(a);

    sort(all(a));

    print128(solve(a, k, n));
    cout << '\n';

    return 0;
}