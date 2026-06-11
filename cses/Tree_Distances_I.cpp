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
int maxdis=-1,far=-1;
void solve(int u,int p,int dis,vi& dist){
    if(maxdis<dis){
        maxdis=dis;
        far=u;
    }
    for(auto x:adj[u]){
        if(x==p) continue;
        dist[x]=dist[u]+1;
        solve(x,u,dis+1,dist);
    }
}
int main() {
    fast;

        ll n; cin>>n;
       adj.assign(n+1,{});
       fi(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
       }
       vi dist(n+1),dista(n+1),distb(n+1);
       dist[0]=0;
       dista[0]=0;
       distb[0]=0;
       solve(1,0,0,dist);
       ll a=far;
       maxdis=-1;
       solve(a,0,0,dista);
       ll b=far;
       maxdis=-1;
       solve(b,0,0,distb);

      for(int i=1;i<=n;i++){
        cout<<max(dista[i],distb[i])<<" ";
      }
      cout<<endl;

}