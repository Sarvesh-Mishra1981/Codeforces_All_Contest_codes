#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> s(n);
    unordered_map<long long, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        freq[s[i]]++;
        freq[s[i] + k]++;
        freq[abs(s[i] - k)]++;
    }
    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        if (freq[t[i]] == 0) {
            cout << "NO\n";
            return;
        }
        freq[t[i]]--;
    }
    
    cout << "YES\n";
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