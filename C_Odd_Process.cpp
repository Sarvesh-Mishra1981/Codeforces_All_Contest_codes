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

int main() {
    fast;
    tc {
        ll n; cin>>n;
        vi v(n); in(v);
        vector<ll> odd;
        vector<ll> even;
        fi(i,0,n){
            if(v[i]%2==0){
                even.push_back(v[i]);
            }else {
                odd.push_back(v[i]);
            }
        }
        sort(all(odd), greater<ll>());
        sort(all(even), greater<ll>());
        ll oc =odd.size();
        ll ec =even.size();
        vector<ll> pref_even(ec+1,0);
        fi(i, 0, ec) {
            pref_even[i+1]=pref_even[i]+even[i];
        }

        fi(k, 1, n + 1) {
            if (oc==0) {
                cout << "0 ";
                continue;
            }      
            ll count_evens=min(k - 1, ec);
            ll needed_extra_odds = (k - 1) - count_evens;
            if (needed_extra_odds % 2 != 0) {
                count_evens--;
                needed_extra_odds++;
            }
            if (count_evens<0 || (1+needed_extra_odds)>oc) {
                cout << "0 ";
            } else {
                ll score=odd[0]+pref_even[count_evens];
                cout<<score<<" ";
            }
        }
        nl;
    }
    return 0;
}