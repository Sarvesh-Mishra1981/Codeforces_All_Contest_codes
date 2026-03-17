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
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll x=gcd(a,b);
    return (a/x)*b;
}
void solve(ll a,ll b,ll c,ll m){
 ll lcm_ab = lcm(a, b);
 ll lcm_bc = lcm(b, c);
 ll lcm_ac = lcm(a, c);
 ll lcm_abc = lcm(a, lcm(b, c));

    ll A=m/a;
    ll B=m/b;
    ll C=m/c;

    ll AB=m/lcm_ab;
    ll BC=m/lcm_bc;
    ll AC=m/lcm_ac;
    ll ABC=m/lcm_abc;
ll only_a=A-AB-AC+ABC;
ll only_b=B-AB-BC+ABC;
ll only_c=C-BC-AC+ABC;
ll AB_only=AB-ABC;
ll BC_only=BC-ABC;
ll AC_only=AC-ABC;
ll fa=6*only_a+3*AB_only+3*AC_only+2*ABC;
ll fb=6*only_b+3*AB_only+3*BC_only+2*ABC;
ll fc=6*only_c+3*AC_only+3*BC_only+2*ABC;

cout<<fa<<" "<<fb<<" "<<fc<<endl;

}

int main() {
    fast;
    tc {
        ll a,b,c,m; cin>>a>>b>>c>>m;
        solve(a,b,c,m);
    }
}