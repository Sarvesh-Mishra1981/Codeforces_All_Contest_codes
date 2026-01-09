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
ll BinarySearch(vi& pmax,ll n,ll target){
   ll l=0,e=n-1;
   ll ans=-1;
   while(l<=e){
    ll mid=l+(e-l)/2;
    if(pmax[mid]<=target){
        ans=mid;
        l=mid+1;
    }else{
        e=mid-1;
    }
   }
return ans;
}

int main() {
    fast;
    tc {
        ll n,k; cin>>n>>k;
        vi a(n); in(a);
        vi b(k); in(b);
         vi pmax(n);
    vi psum(n);
    pmax[0]=a[0];
    psum[0]=a[0];
    fi(i,1,n){
        pmax[i]=max(pmax[i-1],a[i]);
        psum[i]=a[i]+psum[i-1];
    }
    fi(i,0,k)
   { 
    ll idx=BinarySearch(pmax,n,b[i]);
    if(idx==-1) cout<<0<<" ";
    else cout<<psum[idx]<<" ";
}
cout<<endl;
    }
}
