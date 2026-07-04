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
        ll n,m; cin>>n>>m;
        vector<string> a(n);
        for(ll i=0;i<n;i++){
            string s;
            cin>>s;
            a.push_back(s);
        }
        ll i,j;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]=='A'){
                    break;
                }
            }
        }
        vector<vector<pair<ll,ll>>> par(n+1,vector<pair<ll,ll>>(m+1,{-1,-1}));
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
        vvi dist(n+1,vi(m+1,0));
        vi dx={0,0,-1,1};
        vi dy={-1,1,0,0};
        vector<char> mv={'L','R','U','D'};
        vector<vector<char>> moves(n+1,vector<char>(m+1));
        queue<pair<ll,ll>> q;
        q.push({i,j});
        vis[i][j]=true;
        par[i][j]={0,0};
        while(!q.empty()){
            ll x=q.front().ff;
            ll y=q.front().ss;
            q.pop();
            for(ll k=0;k<4;k++){
                ll nx=dx+x;
                ll ny=dy+y;
                if(nx<0|| nx>=n || ny<0 || ny>=m){
                    continue;
                }
                if(!vis[nx][ny]){
                    continue;
                }
                if(a[nx][ny]=='#' || a[nx][ny]=='M'){
                    continue;
                }
                vis[nx][ny]=true;
                par[nx][ny]={x,y};
                dist[nx][ny]=dist[x][y]+1;
                moves[nx][ny]=mv[k];
                q.push({nx,ny});
            }
        }
        ll ex=-1,ey=-1;
        ll min_dis=INT_MAX;
        for(ll t=0;t<m;t++){
            if(vis[0][t] && dist[0][t]<min_dis){
                ex=0;
                ey=t;
            }
            if(vis[n-1][t] && dist[n-1][t]<min_dis){
                ex=n-1;
                ey=t;
            }
        }
        for(ll t=0;t<n;t++){
            if(vis[t][0] && dist[t][0]<min_dis){
                ex=t;
                ey=0;
            }
            if(vis[t][m-1] && dist[t][m-1]<min_dis){
                ex=t;
                ey=m-1;
            }
        }
        if(ex==-1){
            cout<<"NO"<<endl;
            return 0;
        }
       cout<<"Yes"<<endl;
       string ans;
       pi cur={ex,ey};
       pi st={i,j};
       while(cur!=st){
        ans.push_back(moves[cur.ff][cur.ss]);
        cur=par[cur.ff][cur.ss];
       }
       reverse(all(ans));
       cout<<ans<<endl;

}