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
void solve(vi& a,ll n,ll h){
    vi pre(n,0);
    vi suf(n,0);
    for(ll i=0;i<n;i++){
        ll maxi_l=a[i];
        ll maxi_r=a[i];
        ll sum_i=(h-a[i]);
        for(ll j=i-1;j>=0;j--){
            maxi_l=max(maxi_l,a[j]);
            sum_i+=(h-maxi_l);
        }
        pre[i]=max(pre[i],sum_i);
        ll curr_sum=sum_i;
        for(ll j=i+1;j<n;j++){
            maxi_r=max(maxi_r,a[j]);
            curr_sum+=(h-maxi_r);
            pre[j]=max(pre[j],curr_sum);
        }
    }
    for(ll i=n-1;i>=0;i--){
        ll maxi_l=a[i];
        ll maxi_r=a[i];
        ll sum_i=(h-a[i]);
        for(ll j=i+1;j<n;j++){
            maxi_r=max(maxi_r,a[j]);
            sum_i+=(h-maxi_r);
        }
        suf[i]=max(suf[i],sum_i);
        ll curr_sum=sum_i;
        for(ll j=i-1;j>=0;j--){
            maxi_l=max(maxi_l,a[j]);
            curr_sum+=(h-maxi_l);
            suf[j]=max(suf[j],curr_sum);
        }
    }
    fi(i,1,n){
        pre[i]=max(pre[i],pre[i-1]);
    }
    for(ll i=n-2;i>=0;i--){
        suf[i]=max(suf[i],suf[i+1]);
    }
    ll res=max(pre[n-1],suf[0]);
    fi(i,0,n-1){
        res=max(res,pre[i]+suf[i+1]);
    }
    cout<<res<<endl;
}

int main() {
    fast;
    tc {
        ll n,h; cin>>n>>h;
        vi a(n); in(a);
        solve(a,n,h);
    }
}