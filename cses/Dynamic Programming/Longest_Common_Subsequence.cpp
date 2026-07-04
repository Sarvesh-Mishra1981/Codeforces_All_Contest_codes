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

ll solve(vi& a,vi& b,ll n,ll m,ll idx1,ll idx2,vvi & dp){
    if(idx1==n || idx2==m){
        return 0;
    }
    ll res=0;
    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }
    if(a[idx1]==b[idx2]){
        res=1+solve(a,b,n,m,idx1+1,idx2+1,dp);
    }else{
        ll ne=solve(a,b,n,m,idx1+1,idx2,dp);
        ll be=solve(a,b,n,m,idx1,idx2+1,dp);
        res=max(ne,be);
    }
    return dp[idx1][idx2]=res;
}
void build(ll i,ll j,vi& a,vi& b,vi& ans,vvi& dp){

    if(i==a.size() || j==b.size())
        return;

    if(a[i]==b[j]){
        ans.push_back(a[i]);
        build(i+1,j+1,a,b,ans,dp);
    }
    else if(solve(a,b,a.size(),b.size(),i,j+1,dp) >
            solve(a,b,a.size(),b.size(),i+1,j,dp)){
        build(i,j+1,a,b,ans,dp);
    }
    else{
        build(i+1,j,a,b,ans,dp);
    }
}

int main() {
    fast;
        ll n,m; cin>>n>>m;
        vi a(n); in(a);
        vi b(m); in(b);
        vi curr;
        vvi dp(n+1,vi(m+1,-1));
        ll res=solve(a,b,n,m,0,0,dp);
        build(0,0,a,b,curr,dp);
        if(res==0){
cout<<res<<endl;
        }else{
            cout<<res<<endl;
            out(curr);
            nl;
        }

}