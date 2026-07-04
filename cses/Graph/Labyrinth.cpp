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
#define vvpi vector<vector<pi>>
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

using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    pii st, en;

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') st = {i,j};
            if(grid[i][j] == 'B') en = {i,j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m,false));
    vector<vector<pii>> par(n, vector<pii>(m, {-1,-1}));
    vector<vector<char>> move(n, vector<char>(m));

    queue<pii> q;
    q.push(st);
    vis[st.first][st.second] = true;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    char dir[] = {'U','D','L','R'};

    while(!q.empty()) {

        auto [x,y] = q.front();
        q.pop();

        for(int k=0;k<4;k++) {

            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;

            if(vis[nx][ny])
                continue;

            if(grid[nx][ny]=='#')
                continue;

            vis[nx][ny]=true;
            par[nx][ny]={x,y};
            move[nx][ny]=dir[k];

            q.push({nx,ny});
        }
    }

    if(!vis[en.first][en.second]) {
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";

    string ans;

    pii cur=en;

    while(cur!=st) {

        ans.push_back(move[cur.first][cur.second]);
        cur=par[cur.first][cur.second];
    }

    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";
}