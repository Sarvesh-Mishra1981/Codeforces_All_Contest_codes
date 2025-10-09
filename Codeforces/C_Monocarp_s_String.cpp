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
        string s;
        cin >> n >> s;

        int total_a = count(s.begin(), s.end(), 'a');
        int total_b = n - total_a;
        int diff = total_a - total_b;

        // If all are 'a' or all are 'b', impossible to balance
        if (total_a == 0 || total_b == 0) {
            cout << -1 << '\n';
            continue;
        }

        unordered_map<int, int> first_occurrence;
        first_occurrence[0] = 0; // prefix sum before start
        int prefix = 0;
        int ans = n + 1; // large number

        for (int i = 0; i < n; ++i) {
            prefix += (s[i] == 'a' ? 1 : -1);
            // We need prefix[l] = prefix[r] - diff  → check if exists
            if (first_occurrence.count(prefix - diff)) {
                int l = first_occurrence[prefix - diff];
                int r = i + 1;
                ans = min(ans, r - l);
            }
            // only store first occurrence to ensure shortest window
            if (!first_occurrence.count(prefix))
                first_occurrence[prefix] = i + 1;
        }

        if (ans == n + 1)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}
