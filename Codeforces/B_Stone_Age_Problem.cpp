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
        ll n,q; cin>>n>>q;
        vi a(n); in(a);
        ll sum=0;
        fi(i,0,n){
        sum+=a[i];
    }
    bool lastocc=false;
    ll lastval=0;
    vector<bool> changed(n,false);
        while(q--){
            ll tp;
            cin>>tp;
            if(tp==1){
                ll idx,val;
                cin>>idx>>val;
                ll old;
                if(lastocc && !changed[idx-1]){
                   old=lastval;
                }else{
                    old=a[idx-1];
                }
                sum+=-old+val;
                a[idx-1]=val;
                changed[idx-1]=true;
                cout<<sum<<endl;
            }else{
                ll val;
                cin>>val;
                lastocc=true;
                lastval=val;
                sum=(n*val);
                fill(changed.begin(), changed.end(), false);
                cout<<sum<<endl;

            }
        }
}
