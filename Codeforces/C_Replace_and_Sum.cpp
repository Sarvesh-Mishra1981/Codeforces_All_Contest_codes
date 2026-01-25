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
vi preSum(vi& a,ll n){
    vi pre(n);
    pre[0]=a[0];
    fi(i,1,n){
        pre[i]=pre[i-1]+a[i];
    }
    return pre;
}
ll getRangeSum(vi& pre, ll l, ll r){
    if(l==1) return pre[r-1];
    return pre[r-1]-pre[l-2];
}
vi answer(vi& a,ll n,vector<pair<ll,ll>>& query,ll q){
    vi pre=preSum(a,n);
    vi res;
    fi(i,0,q){
        res.push_back(getRangeSum(pre,query[i].first,query[i].second));
    }
    return res;
}

void solve(ll n,vi& a,vi& b){
    fi(i,0,n){
        a[i]=max(a[i],b[i]);
    }
    ll maxi=a[n-1];
    for(ll i=n-1;i>=0;i--){
        maxi=max(maxi,a[i]);
        a[i]=max(a[i],maxi);
    }
}

int main() {
    fast;
    tc {
        ll n,q; cin>>n>>q;
        vi a(n); in(a);
        vi b(n); in(b);
        vector<pair<ll,ll>> query;
        fi(i,0,q){
            ll x,y;
            cin>>x>>y;
            query.push_back({x,y});
        }
        solve(n,a,b);
        out(answer(a,n,query,q));
        cout<<endl;
    }
}
