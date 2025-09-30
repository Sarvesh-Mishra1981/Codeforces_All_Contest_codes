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
#define ll long long
#define vi vector<ll>
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define in(v) for(auto &x:v) cin>>x
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// Function: get top 3 {value,index} pairs from an array
vector<pair<ll,ll>> Convert(vector<ll>& a) {
    vector<pair<ll,ll>> p(a.size());
    fi(i,0,a.size()){
        p[i] = {a[i], i};
    }
    sort(p.rbegin(), p.rend()); // sort by value descending
    vector<pair<ll,ll>> ans;
    fi(i,0,min(3,(int)p.size())){
        ans.push_back(p[i]);
    }
    return ans;
}

ll solve(vi& a, vi& b, vi& c, int n) {
    auto maxa = Convert(a);
    auto maxb = Convert(b);
    auto maxc = Convert(c);

    ll ans = 0;

    // Try all combinations of top 3 from each
    for(auto &pa : maxa){
        for(auto &pb : maxb){
            for(auto &pc : maxc){
                if(pa.second != pb.second && pb.second != pc.second && pc.second != pa.second){
                    ans = max(ans, pa.first + pb.first + pc.first);
                }
            }
        }
    }
    return ans;
}

int main() {
    fast;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n), b(n), c(n);
        in(a); in(b); in(c);
        cout << solve(a,b,c,n) << '\n';
    }
}
