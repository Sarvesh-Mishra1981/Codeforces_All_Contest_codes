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
   ll w,h,d;
   cin>>w>>h>>d;
   ll n;
   cin>>n;
   
   if(n==1){
    cout<<0<<" "<<0<<" "<<0;
    return 0;
   }
   //i am finding the factors first
   vi factors;
   ll temp=n;
   for(ll i=2;i*i<=temp;i++){
        while(temp%i==0){
            factors.push_back(i);
            temp/=i;
        }
   }
   if(temp>1) factors.push_back(temp);
   ll a=1,b=1,c=1;
   for(auto x:factors){
    if(w%(a*x)==0){
        a*=x;
    }
    else if(h%(b*x)==0){
        b*=x;
    }else if(d%(c*x)==0){
        c*=x;
    }else{
        cout<<-1<<endl;
        return 0;
    }
   }
cout<<(a-1)<<" "<<(b-1)<<" "<<(c-1)<<endl;

}
