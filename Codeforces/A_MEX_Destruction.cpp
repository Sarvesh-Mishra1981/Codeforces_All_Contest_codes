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
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tc ll t;cin>>t;while(t--)

void solve(vi& a, ll n){
    bool all_zero = true;
    bool has_zero = false;

    fi(i,0,n){
        if(a[i] != 0) all_zero = false;
        if(a[i] == 0) has_zero = true;
    }

    if(all_zero) cout << 0 << "\n";
    else if(has_zero) cout << 1 << "\n";
    else cout << 2 << "\n";
}

int main() {
    fast;
    tc {
        ll n; cin >> n;
        vi v(n); in(v);
        solve(v, n);
    }
}
