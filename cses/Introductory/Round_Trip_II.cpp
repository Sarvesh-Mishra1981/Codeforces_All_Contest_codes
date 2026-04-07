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
bool solve(vvi& adj,ll n,vi& par,vector<bool>& vis,ll& st,ll& end,ll src){
    vis[src]=true;
    for(auto & x:adj[src]){
        if(x==par[src]) continue;
        if(!vis[x]){
            par[x]=src;
            if(solve(adj,n,par,vis,st,end,x)){
                return true;
            }
        }
        else{
            st=x;
            end=src;
            return true;   }
        
}
return false;
}
int main() {
    fast;
        ll n,m; cin>>n>>m;
        vector<vector<ll>> adj(n+1);
        fi(i,0,m){
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> vis(n+1,false);
        vi par(n+1,-1);
        ll st=-1,end=-1;
        fi(i,1,n+1){
            if(!vis[i]){
                if(solve(adj,n,par,vis,st,end,i)){
                    break;
                }
            }
        }
        if(st==-1){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        vi ans;
        ans.push_back(st);
        for(ll i=end;i!=st;i=par[i]){
            ans.push_back(i);
        }
         ans.push_back(st);
        cout<<ans.size()<<endl;
        out(ans);
        nl;

}