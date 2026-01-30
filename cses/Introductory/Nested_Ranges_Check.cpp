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
void solve(vector<vector<ll>>& a,ll n){
    vi first(n,0);
    vi sec(n,0);
    sort(a.begin(),a.end(),[&](vector<ll>& c,vector<ll>& d){
        if(c[0]==d[0]) return c[1]>d[1];
        return c[0]<d[0];
    });
    ll mini=LLONG_MAX;
    ll maxi=LLONG_MIN;
    for(ll i=n-1;i>=0;i--){
        if(a[i][1]>=mini){
            first[a[i][2]]=1;
        }
        mini=min(mini,a[i][1]);
    }
    for(ll i=0;i<n;i++){
        if(a[i][1]<=maxi){
            sec[a[i][2]]=1;
        }
        maxi=max(maxi,a[i][1]);
    }
    out(first);
    nl;
    out(sec);
}

int main() {
    fast;

        ll n; cin>>n;
       vector<vector<ll>> a;
       fi(i,0,n){
        ll x,y;
        cin>>x>>y;
        a.push_back({x,y,i});
       }
       solve(a,n);
}