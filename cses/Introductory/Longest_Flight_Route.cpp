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
vi topo(vvi& adj,int n){
    vi inorder(n+1,0);
    fi(i,1,n+1){
        for(auto x:adj[i]){
            inorder[x]++;
        }
    }
    vi ans;
    queue<ll> q;
fi(i,1,n+1){
    if(inorder[i]==0){
        q.push(i);
    }
}
    while(!q.empty()){
        ll tp=q.front();
        ans.push_back(tp);
        q.pop();
        for(auto x:adj[tp]){
            if(--inorder[x]==0){
                q.push(x);
            }
        }
    }
    return ans;
}
void solve(vvi& adj,ll n){
    vi tpo=topo(adj,n);
    vi parent(n+1,-1);
    vi dis(n+1,LLONG_MIN);
    dis[1]=1;
    for(auto& u:tpo){
        for(auto& v:adj[u]){
            if(dis[u]+1>dis[v]){
                dis[v]=dis[u]+1;
                parent[v]=u;
            }
        }
    }
    if(dis[n]<0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<ll>ans;
    ll t=n;
    while(parent[t]!=-1){
        ans.push_back(t);
        t=parent[t];
    }
    ans.push_back(1);
    reverse(all(ans));
    cout<<ans.size()<<endl;
    out(ans);
    nl;
}

int main() {
    fast;
        ll n,m; cin>>n>>m;
        vvi adj(n+1);
        fi(i,0,m){
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
        }
        solve(adj,n);
}