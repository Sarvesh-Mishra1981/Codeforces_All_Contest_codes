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
ll solve(string& a,string & b,ll idx1,ll idx2,vector<vector<ll>>& dp){
    if(idx1==a.length()){
       return b.length()-idx2;
    }
    if(idx2==b.length()){
       return  a.length()-idx1;
    }
    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    ll ans=INT_MAX;
    if(a[idx1]==b[idx2]){
        ans= solve(a,b,idx1+1,idx2+1,dp);
    }else{
        ll del=1+solve(a,b,idx1,idx2+1,dp);
        ll rep=1+solve(a,b,idx1+1,idx2+1,dp);
        ll add=1+solve(a,b,idx1+1,idx2,dp);
        ans=min(del,min(rep,add));
    }
    return dp[idx1][idx2]= ans;
}

int main() {
    fast;
  
       string a;
       string b;
       cin>>a>>b;
       vector<vector<ll>> dp(a.length()+1,vector<ll>(b.length()+1,-1LL));
        cout<<solve(a,b,0,0,dp)<<endl;
}