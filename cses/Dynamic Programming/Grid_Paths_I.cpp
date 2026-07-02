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
ll solve(vector<string>& s,ll i,ll j,ll n,vvi& dp){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ans=0;
    if(j==n-1 || (s[i][j+1]!='*')){
        ans+=solve(s,i,j+1,n,dp)%MOD;
    }
    if(i==n-1 || (s[i+1][j]!='*')){
        ans+=solve(s,i+1,j,n,dp)%MOD;
    }
    return dp[i][j]=(ans)%MOD;
}

int main() {
    fast;
       ll n;
       cin>>n;
       vector<string> s;
       fi(i,0,n){
        string z;
        cin>>z;
        s.push_back(z);
       }
       vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
       if(s[0][0]=='*'){
        cout<<0<<endl;
       }else 
       {cout<<solve(s,0,0,n,dp)<<endl;}
}