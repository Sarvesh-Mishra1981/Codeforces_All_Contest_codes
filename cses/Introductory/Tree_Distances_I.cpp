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
pair<ll,ll> solve(int n,int start,vi& dist){
    dist.assign(n+1,-1);
    dist[start]=0;
    queue<ll> q;
    q.push(start);
    ll fartest=start;
    while(!q.empty()){
        ll top=q.front();
        q.pop();
        for(auto x:adj[top]){
            if(dist[x]==-1){
                dist[x]=dist[top]+1;
                q.push(x);

                if(dist[x]>dist[fartest]){
                    fartest=x;
                }
            }
        }
    }
    return {fartest,dist[fartest]};
}


int main() {
    fast;
        ll n; cin>>n;
        adj.resize(n+1);
        fi(i,0,n-1){
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vi dist,distu,distv;
       int u=solve(n,1,dist).first;
       int v=solve(n,u,distu).first;
       solve(n,v,distv);
        fi(i,1,n+1){
            cout<<max(distu[i],distv[i])<<" ";
        }
        nl;
}