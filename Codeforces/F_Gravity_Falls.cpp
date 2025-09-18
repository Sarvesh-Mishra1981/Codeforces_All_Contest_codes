#include <iostream>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arrays(n);
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arrays[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> arrays[i][j];
        }
        max_len = max(max_len, k);
    }
    vector<int> bottom_row;
    for (int j = 0; j < max_len; j++) {
        vector<int> column_elements;
        for (int i = 0; i < n; i++) {
            if (j < arrays[i].size()) {
                column_elements.push_back(arrays[i][j]);
            }
        }
        sort(column_elements.begin(), column_elements.end());
        if (!column_elements.empty()) {
            bottom_row.push_back(column_elements[0]); 
        }
    }
    for (int i = 0; i < bottom_row.size(); i++) {
        cout << bottom_row[i];
        if (i < bottom_row.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}