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
ll path;
ll n = 7;
bool vis[7][7];
void solve(ll i, ll j,ll idx, string& s) {
    if (i == n-1 && j == 0) {
        if (idx==48) {
            path++;
        }
        return;
    }
    if (idx == 48) return;
    bool hit_up = (i == 0 || vis[i - 1][j]);
    bool hit_down = (i == n - 1 || vis[i + 1][j]);
    bool hit_left = (j == 0 || vis[i][j - 1]);
    bool hit_right = (j == n - 1 || vis[i][j + 1]);
    if (hit_left && hit_right && !hit_up && !hit_down) return;
    if (hit_up && hit_down && !hit_left && !hit_right) return;
    vis[i][j] = true;
    char ch=s[idx];
    if ((ch=='?' || ch=='L')&& j > 0 && !vis[i][j-1]) {
        solve(i, j-1,idx+1, s);
    }
    if ((ch=='?' || ch=='R')&&j < n-1 && !vis[i][j+1]) {
        solve(i, j+1,idx+1, s);
    }
    if ((ch=='?' || ch=='U')&&i > 0 && !vis[i-1][j]) {
        solve(i-1, j,idx+1, s);
    }
    if ((ch=='?' || ch=='D') && i < n-1 && !vis[i+1][j]) {
        solve(i+1, j,idx+1, s);
    }
    vis[i][j] = false;
}

int main() {
    fast;
        string s;
        cin >> s;
        path = 0;
        string curr = "";
        solve(0, 0,0, s);
        cout << path << endl;
}
