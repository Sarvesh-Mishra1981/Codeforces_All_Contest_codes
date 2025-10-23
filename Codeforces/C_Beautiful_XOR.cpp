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
        long long a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }
        long long diff = a ^ b;
        if (diff <= a) {
            cout << 1 << "\n" << diff << "\n";
        } else {
            long long x1 = diff / 2;
            long long x2 = diff ^ x1;
            if (x1 <= a && x2 <= a) {
                cout << 2 << "\n" << x1 << " " << x2 << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}
