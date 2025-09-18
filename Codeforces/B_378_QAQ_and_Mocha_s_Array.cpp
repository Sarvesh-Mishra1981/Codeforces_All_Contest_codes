#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;
bool solve(vector<int>& a, int n) {
    sort(a.begin(),a.end());
    int x =a[0];
    int y =a[1];
    for (int i = 0; i < n; i++) {
        if ((a[i] % x != 0) && (y == -1 || a[i] % y != 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (solve(a, n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
