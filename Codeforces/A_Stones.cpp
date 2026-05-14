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
ll solve(ll a,ll b,ll c,vector<vector<vector<ll>>>& dp){
    ll ans = 0;
    if(dp[a][b][c]!=-1) return dp[a][b][c];
    if(a > 0 && b > 1){
        ans = max(ans,solve(a-1,b-2,c,dp)+3);
    }
    if(b > 0 && c > 1){
        ans = max(ans,solve(a,b-1,c-2,dp)+3);
    }
    return dp[a][b][c]=ans;
}

int main() {
    fast;
    tc {
        ll a,b,c; cin>>a>>b>>c;
         vector<vector<vector<ll>>> dp(
            a + 1,
            vector<vector<ll>>(b + 1,
            vector<ll>(c + 1, -1))
        );
        cout<<solve(a,b,c,dp)<<endl;
    }
}