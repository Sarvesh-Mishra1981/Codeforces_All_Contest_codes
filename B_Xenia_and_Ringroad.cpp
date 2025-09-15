#include<iostream>
#include<vector>
using namespace std;

long long solve(vector<int>& a, int n) {
    int init = 1;
    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= init) {
            sum += (a[i] - init);
        } else {
            sum += (n - init) + a[i]; 
        }
        init = a[i];
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    cout << solve(a, n) << endl;
    return 0;
}
