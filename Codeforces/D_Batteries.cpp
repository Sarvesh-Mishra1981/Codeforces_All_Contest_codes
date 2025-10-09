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
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        cin >> n;
        if(n == -1) exit(0);
        vector<pair<int, int>> queries;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                queries.push_back({i, j});
            }
        }
        sort(queries.begin(), queries.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            int d1 = p1.second - p1.first;
            int d2 = p2.second - p2.first;
            if(d1 != d2) return d1 < d2;
            return p1.first < p2.first;
        });
    }
    return 0;
}