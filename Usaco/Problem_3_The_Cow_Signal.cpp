#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string>& v, int n, int m, int k) {
    vector<string> b;

    for (int i = 0; i < n; i++) {
        string expanded_row = "";
        for (int j = 0; j < m; j++) {
            expanded_row += string(k, v[i][j]);
        }
        for (int r = 0; r < k; r++) {
            b.push_back(expanded_row);
        }
    }
    for (auto &row : b) {
        cout << row << "\n";
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    solve(v, n, m, k);
    return 0;
}
