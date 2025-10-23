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
        int n, k;
        string s;
        cin >> n >> k >> s;

        int lastOne = -k;  
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i - lastOne >= k) {
                    ans++;
                    lastOne = i; 
                } else {
                    lastOne = i;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
