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
vector<vector<ll>> adj;
vector<ll> parent;
vector<bool> vis;

ll start = -1, endd = -1;

bool dfs(ll node, ll par){
    vis[node] = true;

    for(auto x : adj[node]){
        if(x == par) continue;

        if(vis[x]){
            start = x;
            endd = node;
            return true;
        }

        parent[x] = node;
        if(dfs(x, node)) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    adj.resize(n+1);
    parent.resize(n+1);
    vis.resize(n+1, false);

    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs(i, -1)){
                break;
            }
        }
    }

    if(start == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<ll> cycle;
    cycle.push_back(start);

    for(ll v = endd; v != start; v = parent[v]){
        cycle.push_back(v);
    }
    cycle.push_back(start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for(auto x : cycle) cout << x << " ";
}