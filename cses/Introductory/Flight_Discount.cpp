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
        vector<vector<pi>> adj(n+1);
        fi(i,0,m){
            ll x,y,z;
            cin>>x>>y>>z;
            adj[x].push_back({y,z});
        }
       vector<vector<ll>> dist(n+1,vector<ll>(2,LLONG_MAX));
       priority_queue<pair<ll,pi>,vector<pair<ll,pi>>,greater<pair<ll,pi>>> pq;
       pq.push({0,{1,0}});
       dist[1][0]=0;
       while(!pq.empty()){
        ll d=pq.top().ff;
        ll u=pq.top().ss.ff;
        ll used=pq.top().ss.ss;
               pq.pop();
        if(d>dist[u][used]) continue;
        for(auto x:adj[u]){
            ll v=x.ff;
            ll w=x.ss;
            if(dist[u][used]+w<dist[v][used]){
            dist[v][used]=dist[u][used]+w;
            pq.push({dist[v][used],{v,used}});
            }

            if(used==0){
                if(dist[u][0]+w/2<dist[v][1]){
            dist[v][1]=dist[u][0]+w/2;
            pq.push({dist[v][1],{v,1}});
            }
            }
        }
       }
       cout<<min(dist[n][0],dist[n][1]);
}