#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<ll>>
#define fast ios::sync_with_stdio(0);cin.tie(0);

const int Na = 2e5+5;

vvi adj(Na);
vector<bool> used(Na,false);
ll cnt=0;

void solve(ll u,ll par){
    for(auto x:adj[u]){
        if(x!=par){
            solve(x,u);
        }
    }

    if(par!=0 && !used[u] && !used[par]){
        cnt++;
        used[u]=true;
        used[par]=true;
    }
}

int main(){
    fast;
    
    ll n;
    cin>>n;

    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    solve(1,0);

    cout<<cnt<<endl;
}