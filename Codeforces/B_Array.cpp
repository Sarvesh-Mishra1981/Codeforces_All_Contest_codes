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

void solve(){
    ll n;cin>>n;
    vi a(n);in(a);
    fi(i,0,n){
        ll cur=0;
        vpi ev;
        fi(j,i+1,n){
            ll x=a[i];
            ll y=a[j];
            if(x==y)continue;
            ll s=x+y;
            if(y>x){
                ll l=(s>=0)?(s/2):((s-1)/2);
                ev.pb({l+1,1});
            }else{
                cur++;
                ll cv=(s>=0)?((s+1)/2):(s/2);
                ev.pb({cv,-1});
            }
        }
        sort(all(ev));
        ll mx=cur;
        ll m=sz(ev);
        for(ll j=0;j<m;){
            ll cx=ev[j].ff;
            while(j<m&&ev[j].ff==cx){
                cur+=ev[j].ss;
                j++;
            }
            mx=max(mx,cur);
        }
        cout<<mx<<" ";
    }
    nl;
}

int main(){
    fast;
    tc{
        solve();
    }
    return 0;
}