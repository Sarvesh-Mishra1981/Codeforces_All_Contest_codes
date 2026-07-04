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
ll st=-1,en=-1;
bool dfs(vvi& adj,vector<bool>& vis,vi& par,ll u,ll p){
    vis[u]=true;
    for(auto x:adj[u]){
        if(x==p){
            continue;
        }
        if(vis[x]){
            st=x;
            en=u;
            return true;
        }
        par[x]=u;
        if(dfs(adj,vis,par,x,u)) return true;
    }
    return false;
}

int main() {
    fast;
        ll n,m; cin>>n>>m;
        vector<vector<ll>> adj(n+1);
        for(ll i=0;i<m;i++){
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vi par(n+1,0);
        vector<bool> vis(n+1,false);
        for(ll i=1;i<=n;i++){
            if(!vis[i]){
                if(dfs(adj,vis,par,i,-1)){
                    break;
                }
            }
        }
        if(st==-1 && en==-1){
            cout<<"IMPOSSIBLE"<<endl;
        }
        vector<ll> ans;
        ans.push_back(st);
        for(ll i=en;i!=st;i=par[i]){
            ans.push_back(i);
        }
        ans.push_back(st);
        reverse(all(ans));
        cout<<ans.size()<<endl;
        out(ans);
        nl;
}