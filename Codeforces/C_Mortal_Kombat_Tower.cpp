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
ll solve(vi& a,ll i,ll turn,ll n,vector<vector<ll>>& dp){
    if(i>=n) return 0;
    if(dp[i][turn]!=-1) return dp[i][turn];
    if(turn==0){
        ll op1=solve(a,i+1,1,n,dp);
        ll op2=solve(a,i+2,1,n,dp);
        return dp[i][turn]=min(op1,op2);
    }else{
        ll op1=solve(a,i+1,0,n,dp)+a[i];
        ll op2=INT_MAX;
        if(i+1<n){
            op2=solve(a,i+2,0,n,dp)+a[i]+a[i+1];
        }
        return dp[i][turn]=min(op1,op2);
    }

}

int main() {
    fast;
    tc {
        ll n; cin>>n;
        vi a(n); in(a);
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        cout<<solve(a,0,1,n,dp)<<endl;
    }
}