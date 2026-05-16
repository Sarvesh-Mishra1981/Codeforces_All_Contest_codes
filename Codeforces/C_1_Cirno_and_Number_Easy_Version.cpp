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
ll mini;
void solve(ll n,ll a,ll b,ll len,ll cur,ll depth){
    if(depth==len){
        mini=min(mini,llabs(n-cur));
        return;
    }

    if(!(depth==0 && len>1 && a==0))
        solve(n,a,b,len,cur*10+a,depth+1);

    if(!(depth==0 && len>1 && b==0))
        solve(n,a,b,len,cur*10+b,depth+1);
}
ll cnt(ll n){
    if (n == 0) return 1;
    ll ans=0;
    while(n>0){
ans++;
n/=10;
    }
    return ans;
}
int main() {
    fast;
    tc {
        ll n,x; cin>>n>>x;
        ll a,b; cin>>a>>b;
        vi sol;  mini=LLONG_MAX;
        ll len=cnt(n);
        for(ll i=max(1LL,len-1);i<=len+1;i++){
            solve(n,a,b,i,0,0);
        }
        
       cout<<mini<<endl;
    }
}