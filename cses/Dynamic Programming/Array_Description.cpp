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
ll solve(vi& a,ll n,ll m,ll idx,ll prev,vvi& dp){
    if(idx==n){
        return 1;
    }
    if(dp[idx][prev]!=-1){
        return dp[idx][prev];
    }
    ll ans=0;
    if(a[idx]!=0)
   { if(abs(a[idx]-prev)<=1){
        ans+=solve(a,n,m,idx+1,a[idx],dp)%MOD;
    }}
    else{
        for(ll i=1;i<=m;i++){
            if(abs(i-prev)<=1)
           { ans+=solve(a,n,m,idx+1,i,dp)%MOD;}
            }
    }
    return dp[idx][prev]=ans%MOD;
}

int main() {
    fast;
        ll n,m; cin>>n>>m;
        vi a(n); in(a);
        vvi dp(n+1,vi(m+1,-1));
        ll ans=0;
        if(a[0]==0){
            for(ll i=1;i<=m;i++)
           { ans=(ans+(solve(a,n,m,1,i,dp)%MOD))%MOD;}
        }else{
            ans=(ans+solve(a,n,m,1,a[0],dp)%MOD)%MOD;
        }
        cout<<ans<<endl;
}