#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long getThesum(const vector<long long>& a) {
    long long sum = 0;
    for (long long x : a) sum += x;
    return sum;
}

vector<long long> getodds(const vector<long long>& a) {
    vector<long long> res;
    for (long long x : a) {
        if (x % 2 != 0) res.push_back(x);
    }
    sort(res.begin(), res.end());
    return res;
}

long long solve(vector<long long>& a, int n) {
    vector<long long> b = getodds(a);
    int x = b.size();
    long long sum = getThesum(a);

    if (x == 0) return 0;         
    else if (x == 1) return sum;  
    else {
        int y = x / 2;
        for (int i = 0; i < y; i++) {
            sum -= b[i];
        }
        return sum;
    }
}
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
        cout << solve(a, n) << "\n";
    }
    return 0;
}
