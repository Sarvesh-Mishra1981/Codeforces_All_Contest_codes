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
void solve(vector<vector<char>>& a,ll n,ll m){
    fi(i,0,n){
        fi(j,0,m){
            if((i+j)&1){
                if(a[i][j]=='A') {
                    a[i][j]='B';
                }else{
                    a[i][j]='A';
                }
            }else{
                if(a[i][j]=='C') {
                    a[i][j]='D';
                }else{
                    a[i][j]='C';
                }
            }
        }
    }
    fi(i,0,n){
        fi(j,0,m){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

int main() {
    fast;

        ll n,m; cin>>n>>m;
        vector<vector<char>> a(n,vector<char>(m));
        fi(i,0,n){
            fi(j,0,m){
                cin>>a[i][j];
            }
        }
        solve(a,n,m);
}
