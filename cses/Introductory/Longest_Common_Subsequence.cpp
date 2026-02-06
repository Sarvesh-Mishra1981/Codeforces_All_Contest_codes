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
vector<vector<ll>> dp;
ll solve(vi& a,vi& b,ll n,ll m){
   dp.assign(n+1,vector<ll>(m+1,0));
    for(ll i=n-1;i>=0;i--){
        for(ll j=m-1;j>=0;j--){
            if(a[i]==b[j]){
                dp[i][j]=1+dp[i+1][j+1];
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}
vi build_lcs(vi& a, vi& b, ll n, ll m) {
    vi res;
    ll i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            res.push_back(a[i]);
            i++; j++;
        } else if (dp[i + 1][j] >= dp[i][j + 1]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}

int main() {
    fast;
        ll n,m; cin>>n>>m;
        vi a(n); in(a);
        vi b(m); in(b);
        cout<<solve(a,b,n,m)<<endl;
        vi ans=build_lcs(a,b,n,m);
        out(ans);
}