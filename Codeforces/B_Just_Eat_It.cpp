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
ll solve2(vi& a,ll n){
     ll ans=0;
    ll curr=0;
     fi(i,0,n){
        curr=max(curr+a[i],a[i]);
        ans=max(curr,ans);
    }
    return ans;
}
bool solve(vi& a,ll n){
    ll res=accumulate(a.begin(),a.end(),0LL);
    vi x;
    vi y;
    fi(i,0,n){
        if(i!=0){
            x.push_back(a[i]);
        }
        if(i!=n-1){
            y.push_back(a[i]);
        }
    }
ll main=max(solve2(x,n-1),solve2(y,n-1));
return res>main;

}

int main() {
    fast;
    tc {
        ll n; cin>>n;
        vi a(n); in(a);
        if(solve(a,n)) Y;
        else N;
    }
}