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
#include<unordered_map>
using namespace std;
int main() {
    int tc; 
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        map<int, vector<int>> num_appears;
        for (int i = 0; i < n; i++) {
            int l; 
            cin >> l;
            for (int j = 0; j < l; j++) {
                int x; 
                cin >> x;
                num_appears[x].push_back(i);
            }
        }

        bool all = true;
        set<int> unique_sets;

        for (int i = 1; i <= m; i++) {
            if (num_appears[i].size() == 1) {
                unique_sets.insert(num_appears[i][0]);
            }
            if (num_appears[i].empty()) all = false;
        }

        int opt = n - (int)unique_sets.size();
        if (all && opt >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
