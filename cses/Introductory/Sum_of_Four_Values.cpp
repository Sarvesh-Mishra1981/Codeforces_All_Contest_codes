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

void solve(vector<pair<ll,ll>>& a, ll n, ll target){
    sort(a.begin(), a.end()); 
for(ll j=0;j<n;j++){
    for(ll i = j+1; i < n; i++){
        ll l = i + 1;
        ll r = n - 1; 

        while(l < r){
            ll sum = a[j].first+a[i].first + a[l].first + a[r].first;

            if(sum == target){
                cout <<a[j].second+1<<" "<< a[i].second + 1 << " "
                     << a[l].second + 1 << " "
                     << a[r].second + 1 << "\n";
                return;
            }
            else if(sum < target){
                l++;
            }
            else{
                r--;
            }
        }
    }}
    cout << "IMPOSSIBLE\n";
}
int main(){
    fast;

    ll n, target;
    cin >> n >> target;

    vector<pair<ll,ll>> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i; 
    }

    solve(a, n, target);
}
