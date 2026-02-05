#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll  long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll MOD = 1e9+7; // Uppercase MOD

ll solve(vector<vector<char>>& grid, ll N) {
    // dp[i][j] stores the number of ways to reach cell(i, j)
    vector<vector<ll>> dp(N, vector<ll>(N, 0));

    // 1. Initialize First Column
    // If we hit a '*', we break because we can't reach anything below it in the first column
    for (int i = 0; i < N; i++) {
        if (grid[i][0] == '*') break; 
        dp[i][0] = 1;
    }

    // 2. Initialize First Row
    // If we hit a '*', we break because we can't reach anything to the right in the first row
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == '*') break;
        dp[0][j] = 1;
    }

    // 3. Fill the rest of the grid
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            // If the cell is blocked, it remains 0
            if (grid[i][j] == '*') {
                continue;
            }

            // Ways = (From Up) + (From Left)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    
    return dp[N - 1][N - 1];
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    // Edge case: If start or end is blocked, answer is 0
    if(v[0][0] == '*' || v[n-1][n-1] == '*') {
        cout << 0 << endl;
    } else {
        // Corrected function call: only passes vector and size
        cout << solve(v, n);
    }
    return 0;
}