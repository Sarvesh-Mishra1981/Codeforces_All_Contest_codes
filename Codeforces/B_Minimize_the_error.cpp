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
ll solve(vi& a,vi& b,ll n,ll c,ll d){
    priority_queue<ll> pq;
    fi(i,0,n){
            pq.push(abs(a[i]-b[i]));
    }
    ll x=c+d;
    while(x>0){
        ll tp=pq.top();
        pq.pop();
        if(tp==0) break;
        x--;
        tp--;
        pq.push(tp);
    }
    ll sum=0;
    while(!pq.empty()){
        ll val=pq.top();
        sum+=val*val;
        pq.pop();
    }
    if(x&1){
        ++sum;
    }
    return sum;
}

int main() {
    fast;

        ll n,c,d; cin>>n>>c>>d;
        vi a(n); in(a);
        vi b(n); in(b);
        cout<<solve(a,b,n,c,d)<<endl;

}