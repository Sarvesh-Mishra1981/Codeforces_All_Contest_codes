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
void dfs(vector<string>& a,ll n,ll m,ll ei,ll ej,ll i,ll j,vector<vector<bool>>& vis,string curr,vector<string>& ans){
    if(i<0 || i>=n || j<0 || j>=m || a[i][j]=='#'){
        return;
    }
    if(vis[i][j]) return;
    if(i==ei && j==ej){
        ans.push_back(curr);
        return;
    }
    vis[i][j]=true;
    dfs(a,n,m,ei,ej,i+1,j,vis,curr+"D",ans);
    dfs(a,n,m,ei,ej,i-1,j,vis,curr+"U",ans);
    dfs(a,n,m,ei,ej,i,j+1,vis,curr+"R",ans);
    dfs(a,n,m,ei,ej,i,j-1,vis,curr+"L",ans);
    vis[i][j]=false;
}

void solve(vector<string>& a,ll n,ll m,ll si,ll sj,ll ei,ll ej){
vector<string> ans;
string curr="";
vector<vector<bool>> vis(n,vector<bool>(m,false));
dfs(a, n, m, ei, ej, si, sj, vis, curr, ans);
    
    if(ans.empty()) {
        cout << "NO\n";
        return;
    }

    string cur = "";
    ll sz = INT_MAX;
    fi(i, 0, ans.size()){
        if(ans[i].size() < sz){
            cur = ans[i];
            sz = ans[i].size();
        }
    }
    cout << "YES\n";
    cout << sz << "\n";
    cout << cur << "\n";
}

int main() {
    fast;
        ll n,m; cin>>n>>m;
        vector<string> a;
        fi(i,0,n){
            string s;
            cin>>s;
            a.push_back(s);
        }
        ll si=0,sj=0,ei=0,ej=0;
        fi(i,0,n){
            fi(j,0,m){
                if(a[i][j]=='A'){
                    si=i;
                    sj=j;
                }
                if(a[i][j]=='B'){
                    ei=i;
                    ej=j;
                }
            }
        }
        solve(a,n,m,si,sj,ei,ej);

}