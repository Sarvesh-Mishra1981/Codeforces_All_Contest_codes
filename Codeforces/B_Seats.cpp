#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define ll  long long
#define vi  vector<ll>
#define pb  push_back
#define sz(x) ((ll)(x).size())
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define tc  ll t;cin>>t;while(t--)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll solve(ll n, string& s){
    vi v;
    v.pb(-2);
    fi(i,0,n){
        if(s[i]=='1') v.pb(i);
    }
    v.pb(n+1);
    ll ans = 0;
    fi(i,1,sz(v)){
        ll gap = v[i] - v[i-1] - 1;
        ans += gap / 3;
    }
    return ans + (sz(v) - 2); 
}

int main() {
    fast;
    tc {
        ll n; cin>>n;
        string s;
        cin>>s;
        cout<<solve(n,s)<<endl;
    }
}