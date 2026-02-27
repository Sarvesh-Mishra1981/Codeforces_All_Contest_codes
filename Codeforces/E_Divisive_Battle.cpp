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

const int M=1000005;
int sp[M];
void sv(){
    fi(i,1,M) sp[i]=i;
    for(int i=2;i*i<M;i++){
        if(sp[i]==i){
            for(int j=i*i;j<M;j+=i)
                if(sp[j]==j) sp[j]=i;
        }
    }
}
int main(){
    fast;
    sv();
    tc{
        ll n;cin>>n;
        vi a(n);fi(i,0,n)cin>>a[i];
        if(is_sorted(all(a))){
            cout<<"Bob\n";
            continue;
        }
        bool aw=0;
        vi b(n);
        fi(i,0,n){
            ll x=a[i];
            if(x==1){
                b[i]=1;
                continue;
            }
            ll p=sp[x];
            b[i]=p;
            while(x%p==0)x/=p;
            if(x>1){
                aw=1;
                break;
            }
        }
        if(aw) cout<<"Alice\n";
        else{
            if(is_sorted(all(b))) cout<<"Bob\n";
            else cout<<"Alice\n";
        }
    }
}