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
#define vvi vector<vector<ll>>
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
    unordered_map<char,ll> w;
    unordered_map<char,ll> b;
    w['Q']=9;w['K']=0;w['P']=1;w['R']=5;w['B']=3;w['N']=3;
    b['q']=9;b['k']=0;b['p']=1;b['r']=5;b['b']=3;b['n']=3;
    ll bans=0,wans=0;
       fi(i,0,8){
        string x;
        cin>>x;
        for(auto ch:x){
            if(w.find(ch)!=w.end()){
                wans+=w[ch];
            }
             if(b.find(ch)!=b.end()){
                bans+=b[ch];
            }
        }
       }
       if(wans==bans){
        cout<<"Draw"<<endl;
       }else if(wans>bans){
        cout<<"White"<<endl;
       }else{
        cout<<"Black"<<endl;
       }

}