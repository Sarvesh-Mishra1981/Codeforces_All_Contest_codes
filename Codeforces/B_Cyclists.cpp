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
#define ll  long long
#define ld  long double
#define vi  vector<ll>
#define pi  pair<ll,ll>
#define vpi vector<pi>
#define pb  push_back
#define ff  first
#define ss  second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define fd(i,s,e) for(ll i=s;i>e;i--)
#define tc  ll t;cin>>t;while(t--)
#define in(v) for(auto &x:v) cin>>x
#define out(v) for(auto &x:v) cout<<x<<" "
#define inp(v) for(auto &x:v) cin>>x.ff>>x.ss
#define Y cout<<"YES\n"
#define N cout<<"NO\n"
#define nl cout<<'\n'
#define mn3(a,b,c) min(a,min(b,c))
#define mx3(a,b,c) max(a,max(b,c))
#define hi(v) *max_element(all(v))
#define lo(v) *min_element(all(v))
#define dbg(x) cerr<<#x<<"="<<x<<'\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;
const int Na = 2e5+5;

// -----------------------------------Lets Do IT---------------------------------------------------------------
ll solve(vi& a, ll n, ll k, ll p, ll m) {
    ll target_cost = a[p - 1];
    vi b;
    fi(i, 0, p - 1) {
        b.pb(a[i]);
    }
    sort(all(b));
    ll cst_1 = target_cost;
    ll req1 = max(0LL, p - k);
    fi(i, 0, req1) {
        cst_1 += b[i];
    }
    if (m < cst_1) return 0;
    vi c;
    fi(i, 0, n) {
        if (i == p - 1) continue; 
        c.pb(a[i]);
    }
    sort(all(c));
    ll cst_cycle = target_cost;
    ll req2 = max(0LL, n - k);
    fi(i, 0, req2) {
        cst_cycle += c[i];
    }
    m -= cst_1;
    ll ans = 1 + (m / cst_cycle);
    return ans;
}

int main() {
    fast;
    tc {
        ll n, k, p, m; 
        cin >>n>> k >> p >> m;
        vi a(n); 
        in(a);
        
        cout << solve(a, n, k, p, m) << '\n';
    }
    return 0;
}