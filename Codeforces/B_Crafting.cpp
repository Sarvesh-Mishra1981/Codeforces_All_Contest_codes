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
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);

bool canCraft(const vi& a, const vi& b, ll n) {
    ll sumA = accumulate(a.begin(), a.end(), 0LL);
    ll sumB = accumulate(b.begin(), b.end(), 0LL);
    if (sumA < sumB) return false;

    ll maxA = *max_element(a.begin(), a.end());
    ll maxB = *max_element(b.begin(), b.end());
    if (maxA < maxB) return false;

    return true;
}

int main() {
    fast;
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vi a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        cout << (canCraft(a, b, n) ? "YES\n" : "NO\n");
    }
}
