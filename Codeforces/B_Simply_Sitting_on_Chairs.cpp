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
ll solve(vi& a,ll idx,ll n,vector<bool>& vis){
    if(idx==n) return 0;
    if(vis[idx]){
       return solve(a,idx+1,n,vis);
    }else{
                vis[a[idx]]=true;
        ll take=1+solve(a,idx+1,n,vis);
        vis[a[idx]]=false;
       ll nottake= solve(a,idx+1,n,vis);
       return max(take,nottake);
    }
}
// ll solve(vi& a,ll n,vector<bool>& vis){
//     fi(i,0,n){
//         if(i+1<a[i]){
//             vis[a[i]]=true;
//         }
//     }
//     ll maxi=0,t=0;
//     fi(i,0,n+1){
//         if(vis[i]){
//             t+=1;
//         }
//         maxi=max(maxi,i-t);
//     }
//     return maxi;
// }

int main() {
    fast;
    tc {
        ll n; cin>>n;
        vi a(n); in(a);
        vector<bool> vis(n+1,false);
        cout<<solve(a,0,n,vis)<<endl;
    }
}