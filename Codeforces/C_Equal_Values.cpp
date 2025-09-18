#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

bool isAllsame(vector<int>& a) {
    unordered_set<int> m(a.begin(), a.end());
    return (m.size() == 1);
}

int solve(vector<int>& a, int n) {
    if (isAllsame(a)) return 0;

    int sum = INT_MAX;
    for (int i = 0; i < n; i++) {
        int res = (i * a[i]) + ((n - i - 1) * a[i]);
        sum = min(sum, res);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        vector<int> a(x);
        for (int i = 0; i < x; i++) {
            cin >> a[i];
        }
        cout << solve(a, x) << endl;
    }
}
