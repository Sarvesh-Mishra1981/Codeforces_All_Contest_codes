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
#define mx4(a,b,c,d) max(a,max(b,max(c,d)))
#define hi(v) *max_element(all(v))
#define lo(v) *min_element(all(v))
#define dbg(x) cerr<<#x<<"="<<x<<'\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;
const int Na = 2e5+5;

// -----------------------------------Lets Do IT---------------------------------------------------------------


int main() {
    fast;
    tc {
         ll w, h;            
        cin >> w >> h;
        int k;
        cin >> k;
        vi bottom(k);
        in(bottom);
        cin >> k;
        vi top(k);
        in(top);
        cin >> k;
        vi leftSide(k);
        in(leftSide);
        cin >> k;
        vi rightSide(k);
        in(rightSide);
        ll a=(bottom[bottom.size()-1]-bottom[0])*h;
        ll b=(top[top.size()-1]-top[0])*h;
        ll c=(leftSide[leftSide.size()-1]-leftSide[0])*w;
        ll d=(rightSide[rightSide.size()-1]-rightSide[0])*w;
        ll ans=mx4(a,b,c,d);
        cout<<ans<<endl;
    }
}
