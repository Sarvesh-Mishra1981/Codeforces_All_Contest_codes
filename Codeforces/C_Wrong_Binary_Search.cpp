#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long
#define vi vector<ll>
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define fd(i,s,e) for(ll i=s;i>=e;i--)
#define tc ll t;cin>>t;while(t--)
#define out(v) for(auto &x:v) cout<<x<<" "
#define Y cout<<"YES\n"
#define N cout<<"NO\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(string& s, ll n) {
    ll c1 = 0;
    fi(i,0,n) {
        if(s[i]=='1') c1++;
    }

    if(c1 > 0 && c1 % 2 == 0) {
        N;
        return;
    }

    vi res(n, -1);

    // Step 1: assign positions for '1'
    fi(i,0,n) {
        if(s[i]=='1') res[i] = i+1;
    }

    // Step 2: assign numbers for '0' from 1 increasing
    ll num = 1;
    fd(i,n-1,0) {
        if(s[i]=='0') {
            while(find(res.begin(), res.end(), num) != res.end()) {
                num++;
            }
            res[i] = num;
            num++;
        }
    }

    Y;
    out(res);
    cout << "\n";
}

int main() {
    fast;
    tc {
        ll n; cin >> n;
        string s; cin >> s;
        solve(s, n);
    }
    return 0;
}
