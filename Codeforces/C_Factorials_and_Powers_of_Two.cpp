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
ll setbit(ll a){
    ll res=0;
    while(a>0){
        a=a&(a-1);
        res++;
    }
    return res;
}
ll solve(ll n){
    vector<ll> fact(15);
    vi fac;
    fact[0]=1;
    fi(i,1,15){
        fact[i]=fact[i-1]*i;
    }
    fi(i,3,15){
        fac.push_back(fact[i]);}
        ll ans=INT_MAX;
    for(auto m=0;m<(1LL<<12);m++){
        ll cnt=0;
        ll sum=0;
        fi(i,0,12){
            if(m&(1<<i)){
                sum+=fac[i];
                cnt++;
            }
        }
        if(sum>n) continue;
        cnt+=setbit(n-sum);
        ans=min(ans,cnt);
    }
        return ans;

}

int main() {
    fast;
    tc {
        ll n; cin>>n;
        cout<<solve(n)<<endl;
    }
}