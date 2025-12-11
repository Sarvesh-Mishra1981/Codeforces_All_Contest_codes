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
bool check_gen_fib(const vi& v) {
    if (v.size() < 3) return true; 
    for (size_t i = 2; i < v.size(); i++) {
        if (v[i]!=v[i-2]+v[i-1]) {
            return false;
        }
    }
    return true;
}
void ConvertVal(vector<vector<ll>>& a,vi& val,ll& ans){
    ll n=a.size();
    fi(i,0,n){
        ll m=a[i].size();
        fi(j,0,m){
            ll z=val[a[i][j]];
            a[i][j]=z;
        }
        if(check_gen_fib(a[i])){
            ans++;
        }
    }
}


void BuildAdency(vector<vector<ll>>& adj,ll u,ll v){
    adj[u].push_back(v);
}
void getAllpath(vi& path,vector<vector<ll>>& adj,ll src,ll dest,vector<bool>& visited,vector<vector<ll>>& ans){
    visited[src]=true;
    path.push_back(src);
    if(src==dest){
        ans.push_back(path);
    }else{
        for(auto x:adj[src]){
            if(!visited[x]){
                getAllpath(path,adj,x,dest,visited,ans);
            }
        }
    }
    path.pop_back();
    visited[src]=false;
}
int main() {
    fast;
    tc {
        ll n,m; cin>>n>>m;
        vi v(n); in(v);
        vector<vector<ll>> adj(n+1);
        fi(i,0,m){
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            BuildAdency(adj,x,y);
        }
        vector<ll> path; vector<bool> visited(n,false);
        vector<vector<ll>> Allpaths;
        getAllpath(path,adj,0,n-1,visited,Allpaths);
        ll res=n;
        ConvertVal(Allpaths,v,res);
        cout<<res<<endl;
    }
}
