#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

string solve(vector<int>& a, vector<int>& b, int n, int m, int k) {
    if (n - k >= 2) 
        return string(m, '0');   
    else if (n - k == 0) 
        return string(m, '1');  
    else {
        unordered_set<int> known(b.begin(), b.end());
        int missing = -1;
        for (int i = 1; i <= n; i++) {
            if (known.find(i) == known.end()) {
                missing = i; break;
            }
        }
        string s;
        for (int x : a) {
            if (x == missing) s += '1';
            else s += '0';
        }
        return s;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        vector<int> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
        }
        cout << solve(a, b, n, m, k) << endl;
    }
}
