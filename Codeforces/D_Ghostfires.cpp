#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define ll  long long
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
#define tc  ll t;cin>>t;while(t--)
#define nl cout<<'\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(ll r,ll g,ll b){
    string s;
    s.reserve(r+g+b);
    while(1){
        ll z=sz(s); 
        vector<pair<ll,char>> v={{r,'R'},{g,'G'},{b,'B'}};
        sort(all(v),[&](pair<ll,char>&a,pair<ll,char>&b){
            if(a.ff!=b.ff)return a.ff>b.ff;
            bool p1=(z>=2&&s[z-2]==a.ss);
            bool p2=(z>=2&&s[z-2]==b.ss);
            return p1>p2;
        });
        bool ok=0;
        for(auto p:v){
        if(p.ff==0)continue;
            if(z>=1&&s[z-1]==p.ss)continue;
     if(z>=3&&s[z-3]==p.ss)continue;
            s+=p.ss;
            if(p.ss=='R')r--;
         if(p.ss=='G')g--;
            if(p.ss=='B')b--;
            ok=1;
            break;
        }
        if(!ok)break;
    }
    cout<<s;nl;
}

int main(){
    fast;
    tc{
          ll r,g,b;cin>>r>>g>>b;
        solve(r,g,b);
    }
    return 0;
}