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
unordered_map<ll,ll> longestStreaks(vector<ll>& arr) {
    unordered_map<ll,ll> best;  
    ll n = arr.size();

    ll currVal = arr[0], currLen = 1;
    best[currVal] = max(best[currVal], currLen);

    for (ll i = 1; i < n; i++) {
        if (arr[i] == currVal) {
            currLen++;
        } else {
            best[currVal] = max(best[currVal], currLen);
            currVal = arr[i];
            currLen = 1;
        }
        best[currVal] = max(best[currVal], currLen);
    }
    return best;
}
ll solve(vi &a, vi &b, ll n) {
    unordered_map<ll,ll> streakA = longestStreaks(a);
    unordered_map<ll,ll> streakB = longestStreaks(b);

    ll res = 0;
    unordered_set<ll> values;
    for (auto &p : streakA) values.insert(p.first);
    for (auto &p : streakB) values.insert(p.first);

    for (ll val : values) {
        ll len = streakA[val] + streakB[val]; 
        res = max(res, len);
    }
    return res;
}

int main() {
    fast;
    tc {
        ll n; cin>>n;
        vi v(n); in(v);
        vi a(n); in(a);
        cout<<solve(v,a,n)<<endl;
    }
}
