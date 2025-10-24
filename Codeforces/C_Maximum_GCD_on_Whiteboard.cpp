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
void solve(ll n, ll k, vi &v){
    vi f(n+1,0);
    for(ll x:v) f[x]++;
    vi p(n+1,0);
    for(ll i=1;i<=n;i++) p[i]=p[i-1]+f[i];
    ll ans=1;
    for(ll d=n;d>=1;d--){
        ll ub=min(4*d-1,1LL*n);
        ll tot=(ub>=1?p[ub]:0);
        ll gd=f[d];
        if(2*d<=n) gd+=f[2*d];
        if(3*d<=n) gd+=f[3*d];
        ll bd=tot-gd;
        if(bd<=k){
            ans=d;
            break;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    fast;
    tc{
        ll n,k; cin>>n>>k;
        vi v(n); in(v);
        solve(n,k,v);
    }
}