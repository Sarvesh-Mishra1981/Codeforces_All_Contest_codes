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
vvi adj;
vvi up;
vi depth;
const ll LOG=20;
void solve(ll u,ll p){
    up[u][0]=p;
    for(ll j=1;j<LOG;j++){
        up[u][j]=up[up[u][j-1]][j-1];
    }
    for(auto x:adj[u]){
        if(x==p) continue;
        depth[x]=depth[u]+1;
        solve(x,u);
    }
}
ll lca(ll u,ll v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    ll d=depth[u]-depth[v];
    for(ll j=0;j<LOG;j++){
        if(d&(1<<j)){
            u=up[u][j];
        }
    }
    if(u==v){
        return u;
    }
    for(ll j=LOG-1;j>=0;j--){
        if(up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}
int main() {
    fast;
        ll n,k; cin>>n>>k;
        adj.assign(n+1,{});
        up.assign(n+1,vector<ll>(LOG,0));
        depth.assign(n+1,0);
        for(ll i=2;i<=n;i++){
            ll x;
            cin>>x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
        solve(1,0);
        while(k--){
            ll a,b;
            cin>>a>>b;
          cout<<lca(a,b)<<endl;
        }
}