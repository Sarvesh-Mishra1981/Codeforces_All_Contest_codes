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
// ll solve(vi& a,vi& b,ll k,ll idx,ll n){
//     if(idx==n) return k;
//     ll ans=0;
//     ans=max(solve(a,b,(k-a[idx]),idx+1,n),solve(a,b,b[idx]-k,idx+1,n));
//     return ans;
// }

int main() {
    fast;
    tc {
        ll n; cin>>n;
        vi a(n); in(a);
        vi b(n); in(b);
        ll maxi=0;
        ll mini=0;
        fi(i,0,n){
            ll x=maxi-a[i];
            ll y=b[i]-mini;
            ll new_maxi=max(x,y);
            ll r=mini-a[i];
            ll g=b[i]-maxi;
            ll new_mini=min(r,g);
            maxi=new_maxi;
            mini=new_mini;
        }
      cout<<maxi<<endl;
    }
}
