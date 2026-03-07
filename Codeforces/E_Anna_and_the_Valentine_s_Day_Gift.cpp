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
bool solve(vi& a,ll n,ll m){
    ll cnt=0;
    vi zerocnt;
    fi(i,0,n){
        string s=to_string(a[i]);
        cnt+=s.length();
        ll zero=0;
        for(ll j=s.length()-1;j>=0;j--){
            if(s[j]=='0'){
                zero++;
            }else{
                break;
            }
        }
        zerocnt.push_back(zero);
    }
    sort(rall(zerocnt));
    for(ll i=0;i<n;i+=2){
        cnt-=zerocnt[i];
    }
    return cnt>m;
}

int main() {
    fast;
    tc {
        ll n,m; cin>>n>>m;
        vi a(n); in(a);
        if(solve(a,n,m)){
            cout<<"Sasha";
            nl;
        }else{
            cout<<"Anna";
            nl;
        }
    }
}