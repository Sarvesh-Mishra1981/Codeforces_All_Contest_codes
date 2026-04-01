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
bool dfs(vector<vector<ll>>& adj,ll src,vector<bool>& vis,vector<ll>& col,ll val){
    vis[src]=true;
    col[src]=val;
    for(auto& x:adj[src]){
        if(!vis[x]){
            if(!dfs(adj,x,vis,col,3-val)){
                return false;
            }
        }else if(col[src]==col[x]){ return false;}
    }
    return true;
}

int main() {
    fast;
        ll n,m; cin>>n>>m;
        vector<vector<ll>> adj(n+1);
        fi(i,0,m){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n+1,false);
        vector<ll> col(n+1,0);
        bool flag=false;
        fi(i,1,n+1){
            if(!vis[i]){
                if(!dfs(adj,i,vis,col,1)){
                    flag=true;
                    break;
                }
            }
        }
        if(flag){
            cout<<"IMPOSSIBLE"<<endl;
        }else{ fi(i,1,n+1){
            cout<<col[i]<<" ";
        }}
        nl;
}