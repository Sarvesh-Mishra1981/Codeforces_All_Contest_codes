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
int pre[30][200001];
ll val(ll l, ll r) {
    ll ans = 0;
    fi(i, 0, 30) {
        if(pre[i][r+1] - pre[i][l] == 0) {
            ans |= (1LL << i); 
        }
    }
    return ans;
}

void solve(vector<ll>& a, ll n, vector<pair<ll,ll>>& b, ll q) {
    fi(i, 0, q) {
        ll k = b[i].second;
        ll l = b[i].first - 1; 
        
        if(a[l] < k) {
            cout << -1 << " ";
            continue;
        }
        
        ll low = l, high = n - 1;
        ll best_r = l;
        
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(val(l, mid) >= k) {
                best_r = mid; 
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        cout << best_r + 1 << " ";
    }
    nl;
}

int main() {
    fast;
    tc {
        ll n; cin>>n;
        vector<ll> a(n);
        in(a);
        ll q; cin>>q;
        vector<pair<ll,ll>> b(q);
        for(ll i=0;i<q;i++){
            cin>>b[i].first>>b[i].second;
        }

        for(ll j=0;j<30;j++){
            pre[j][0]=0;
            fi(i,0,n){
                if((1<<j)&a[i]){
                    pre[j][i+1]=pre[j][i];
                }else{
                    pre[j][i+1]=pre[j][i]+1;
                }
            }
        }
        solve(a,n,b,q);
    }
}