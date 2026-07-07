#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> solve(vector<vector<ll>> &edges, ll n, ll m)
{
    vector<ll> dist(n + 1, 0);    
    vector<ll> par(n + 1, -1);

    ll x = -1;

    for (ll i = 1; i <= n; i++)
    {
        x = -1;
        for (ll j = 0; j < m; j++)
        {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll w = edges[j][2];

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
        return {};

    // Move inside the negative cycle
    for (ll i = 0; i < n; i++)
        x = par[x];

    vector<ll> cycle;
    ll cur = x;

    do
    {
        cycle.push_back(cur);
        cur = par[cur];
    } while (cur != x);

    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    return cycle;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> edges(m, vector<ll>(3));

    for (ll i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<ll> ans = solve(edges, n, m);

    if (ans.empty())
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}