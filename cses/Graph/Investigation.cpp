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
#define vvi vector<vector<ll>>
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


int main() {
    fast;
        ll n,m; cin>>n>>m;
        vector<vector<pair<ll,ll>>> adj(n+1);
        for(ll i=0;i<m;i++){
            ll x,y,z;
            cin>>x>>y>>z;
            adj[x].push_back({y,z});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
        pq.push({0,1});
        vector<ll>dist(n+1,LLONG_MAX);
        vector<ll> minr(n+1,LLONG_MAX);
        vector<ll> maxr(n+1,LLONG_MIN);
         vector<ll> ways(n+1,0);
        dist[1]=0;
        maxr[1]=0;
        minr[1]=0;
        ways[1]=1;
        while(!pq.empty()){
            ll d=pq.top().first;
            ll u=pq.top().second;
            pq.pop();
            if(d>dist[u]) continue;
            for(auto x:adj[u]){
                ll v=x.first;
                ll w=x.second;
                if(dist[u]+w<=dist[v]){
                
                    if (dist[u] + w < dist[v]) {
    dist[v] = dist[u] + w;
    ways[v] = ways[u];
    minr[v] = minr[u] + 1;
    maxr[v] = maxr[u] + 1;
    pq.push({dist[v], v});
}
else if (dist[u] + w == dist[v]) {
    ways[v] = (ways[v] + ways[u]) % MOD;
    minr[v] = min(minr[v], minr[u] + 1);
    maxr[v] = max(maxr[v], maxr[u] + 1);
}

                }
            }
        }
        cout<<dist[n]<<" "<<ways[n]<<" "<<minr[n]<<" "<<maxr[n];
}