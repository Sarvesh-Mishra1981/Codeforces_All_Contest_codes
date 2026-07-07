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
ll ed=-1;
ll st=-1;
bool dfs(vector<vector<ll>>& adj,vector<bool>& vis,vector<bool>& rec,vector<ll>& par,ll src,ll p){
    vis[src]=true;
    rec[src]=true;
    par[src]=p;
    for(auto x:adj[src]){
        if(!vis[x]){
            if(dfs(adj,vis,rec,par,x,src)){
                return true;
            }
        }else if(rec[x]){
            ed=x;
            st=src;
            return true;
        }
    }
    rec[src]=false;
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
        }
        vector<ll> par(n+1,-1);
        vector<bool> vis(n+1,false);
        vector<bool> rec(n+1,false);
        bool flag=false;
        for(ll i=1;i<=n;i++){
            if(!vis[i]){
                if(dfs(adj,vis,rec,par,i,0)){
                    flag=true;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            vector<ll> cyc;

cyc.push_back(ed);

ll cur = st;

while(cur != ed){
    cyc.push_back(cur);
    cur = par[cur];
}

cyc.push_back(ed);

reverse(cyc.begin(), cyc.end());
            cout<<cyc.size()<<endl;
            out(cyc);
        }
        return 0;
}