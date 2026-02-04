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
ll solve(vector<pair<ll,ll>>& a, ll n, ll k) {
    // 1. Sort by End Time (Ascending)
    sort(a.begin(), a.end(), [&](pair<ll,ll>& x, pair<ll,ll>& y){
        if(x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    });

    multiset<ll> rooms; // Stores the end time of the last activity in each room
    ll ans = 0;

    // 2. Iterate through sorted intervals
    for(ll i = 0; i < n; i++) {
        ll start = a[i].first;
        ll end = a[i].second;

        // Find the first room that finishes AFTER our start time
        auto it = rooms.upper_bound(start);

        if (it != rooms.begin()) {
            // If we found a room that finishes AFTER start, the one BEFORE it
            // finishes <= start. This is the room we want.
            it--; 
            rooms.erase(it);   // Remove the old finish time
            rooms.insert(end); // Update with new finish time
            ans++;
        } 
        else if (rooms.size() < k) {
            // If no existing room is free, but we haven't used all k rooms yet
            rooms.insert(end);
            ans++;
        }
        // If it == begin() AND size == k, we cannot schedule this interval. Skip it.
    }
    return ans;
}
int main() {
    fast;
        ll n,k; cin>>n>>k;
       vector<pair<ll,ll>> a(n);
       fi(i,0,n){
        cin>>a[i].first>>a[i].second;
       }
       cout<<solve(a,n,k)<<endl;
}