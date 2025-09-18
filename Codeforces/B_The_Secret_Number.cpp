#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<long long> solve(long long n) {
    vector<long long> a;
    long long power = 1;
    for (int i = 1; i <= 18; i++) {
        power *= 10; 
        long long d = 1 + power;
        if (n % d == 0) {
            a.push_back(n / d);
        }
    }
    sort(a.begin(), a.end());
    return a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a = solve(n);
        if (a.empty()) {
            cout << 0 << endl;
        } else {
            cout << a.size() << endl;
            for (long long p : a) {
                cout << p << " ";
            }
            cout << endl;
        }
    }
    return 0;
}