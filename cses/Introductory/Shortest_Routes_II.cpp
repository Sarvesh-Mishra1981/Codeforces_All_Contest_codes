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
        ll n,m,q; cin>>n>>m>>q;
        vector<vector<ll>> dist(n+1,vector<ll>(n+1,LLONG_MAX));
        fi(i,0,n+1){
            dist[i][i]=0;
        }
        fi(i,0,m){
            ll x,y,z;
            cin>>x>>y>>z;
            dist[x][y]=min(dist[x][y],z);
            dist[y][x]=min(dist[y][x],z);
        }
        for(ll k=1;k<=n;k++){
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    if(dist[i][k]!=LLONG_MAX && dist[j][k]!=LLONG_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        while(q--){
            ll x,y;
            cin>>x>>y;
            if(dist[x][y]==LLONG_MAX) cout<<-1<<endl;
            else cout<<dist[x][y]<<endl;
        }
}