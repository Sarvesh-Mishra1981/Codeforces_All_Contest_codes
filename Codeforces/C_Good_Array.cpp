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
void solve(vi& a,ll n){
    map<ll,ll> m;
    fi(i,0,n){
        m[a[i]]++;
    }
    ll sum= accumulate(a.begin(),a.end(),0LL);
    vector<ll> ans;
    fi(i,0,n){
        if(--m[a[i]]==0) m.erase(a[i]);

        ll target=(sum-a[i]);
        if(target%2==0) {
            target/=2;
        if(m.count(target)){
            ans.push_back(i+1);
        }
        }
        m[a[i]]++;
    }
    cout<<ans.size()<<endl;
    if(ans.size()==0){
        return;
    }

    fi(i,0,ans.size()){

        cout<<ans[i]<<" ";
    }
    nl;
}

int main() {
    fast;
        ll n; cin>>n;
        vi a(n); in(a);
        solve(a,n);
}