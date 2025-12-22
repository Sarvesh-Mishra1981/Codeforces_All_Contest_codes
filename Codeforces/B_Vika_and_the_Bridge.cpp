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
        ll n,k; cin>>n>>k;
        vi v(n); in(v);
        vector<vector<ll>> a(k+1);
        fi(i,1,k+1){
            a[i].push_back(0);
        }
        fi(i,0,n){
            a[v[i]].push_back(i+1);     
        }
        fi(i,1,k+1){
            a[i].push_back(n+1);
        }
        ll ans=INT_MAX;
        for(ll i=1;i<=k;i++){
                    priority_queue<ll> pq;
            for(ll j=0;j<a[i].size()-1;j++){
                pq.push(a[i][j+1]-a[i][j]-1);
            }
            ll top=pq.top();
            pq.pop();
            if(top%2==0){
                pq.push(((top)/2)-1);
                pq.push(top/2);
            }else{
                pq.push(top/2);
                pq.push(top/2);
            }
            ans=min(ans,pq.top());
        }
       cout<<ans<<endl;
    }
}
