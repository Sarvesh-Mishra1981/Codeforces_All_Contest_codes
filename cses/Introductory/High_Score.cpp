#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj;
    vector<vector<ll>> graph(n+1);

    for(int i = 0; i < m; i++){
        ll x,y,z;
        cin >> x >> y >> z;
        adj.push_back({x,y,-z}); // invert
        graph[x].push_back(y);
    }

    vector<ll> dist(n+1, LLONG_MAX);
    dist[1] = 0;

    // Bellman-Ford
    for(int i = 1; i < n; i++){
        for(auto &x : adj){
            ll u = x[0], v = x[1], w = x[2];
            if(dist[u] != LLONG_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    // detect affected nodes
    vector<bool> affected(n+1,false);
    for(auto &x:adj){
        ll u=x[0], v=x[1], w=x[2];
        if(dist[u]!=LLONG_MAX && dist[u]+w < dist[v]){
            affected[v]=true;
        }
    }

    // BFS
    queue<ll> q;
    vector<bool> vis(n+1,false);

    for(int i=1;i<=n;i++){
        if(affected[i]){
            q.push(i);
            vis[i]=true;
        }
    }

    while(!q.empty()){
        ll node=q.front(); q.pop();
        for(auto &nbr:graph[node]){
            if(!vis[nbr]){
                vis[nbr]=true;
                q.push(nbr);
            }
        }
    }

    if(vis[n]){
        cout << -1 << "\n";
    }
    else{
        cout << -dist[n] << "\n";
    }
}