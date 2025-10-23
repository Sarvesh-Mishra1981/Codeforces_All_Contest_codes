#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <iomanip>
#include <utility>
#include<unordered_set>
#include<unistd.h>
#include<unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Apply Operation 1: Set each a[i] to prefix maximum
        vector<long long> pref_max = a;
        for (int i = 1; i < n; i++) {
            pref_max[i] = max(pref_max[i], pref_max[i - 1]);
        }

        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0) { // a[i] < a[i+1]
                if (pref_max[i] >= pref_max[i + 1]) {
                    long long need = pref_max[i] - pref_max[i + 1] + 1;
                    ans += need;
                }
            } else { // a[i] > a[i+1]
                if (pref_max[i] <= pref_max[i + 1]) {
                    long long need = pref_max[i + 1] - pref_max[i] + 1;
                    ans += need;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}