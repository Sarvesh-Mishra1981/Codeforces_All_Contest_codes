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
        for (int i = 0; i < n; i++) cin >> a[i];
        
        // Operation 1: prefix max (non-decreasing)
        for (int i = 1; i < n; i++)
            a[i] = max(a[i], a[i-1]);
        
        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0) {
                // odd index (1-based): need a[i] < a[i+1]
                if (a[i] >= a[i+1]) {
                    long long diff = a[i] - a[i+1] + 1;
                    ans += diff;
                    a[i+1] += diff; // simulate necessary increase pattern
                }
            } else {
                // even index (1-based): need a[i] > a[i+1]
                if (a[i] <= a[i+1]) {
                    long long diff = a[i+1] - a[i] + 1;
                    ans += diff;
                    a[i+1] -= diff;
                }
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}
