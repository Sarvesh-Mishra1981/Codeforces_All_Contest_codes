#include <iostream>
#include<vector>
using namespace std;
#define ll  long long
#define vi  vector<ll>
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define in(v) for(auto &x:v) cin>>x
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tc  ll t;cin>>t;while(t--)

ll solve(vi& v,ll k,ll n){
    ll ce=0;               // count evens
    ll res = k;            // large initial value

    fi(i,0,n){
        if(v[i] % 2 == 0) ce++;
        if(v[i] % k == 0) return 0;   // already divisible
        res = min(res, k - (v[i] % k));
    }
ll x=2;
ll y=1;
    if(k == 4){
        if(ce == 0) return min(res,x);
        else if(ce == 1) return min(res,y);
        else return 0;
    }

    return res;
}

int main() {
    fast;
    tc {
        ll n,k; cin>>n>>k;
        vi v(n); in(v);
        cout << solve(v,k,n) << '\n';
    }
}
