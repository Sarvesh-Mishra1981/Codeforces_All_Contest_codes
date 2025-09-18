#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_sum(vector<int>& a) {
    vector<int> b(a.size());
    b[0] = a[0];
    for (int i = 1; i < a.size(); i++) {
        b[i] = b[i - 1] + a[i];
    }
    return b;
}

int return_sum(vector<int>& pref, int l, int r) {
    if (l == 0) return pref[r];
    return pref[r] - pref[l - 1];
}

vector<int> solve(vector<int>& a, int n) {
    vector<int> res;  
    vector<int> pref = prefix_sum(a);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int x = (return_sum(pref, 0, i))%3;
            int y = (return_sum(pref, i + 1, j))%3;
            int z = (return_sum(pref, j + 1, n - 1))%3;

            if ((x == y && y == z) || (x!=y && y!=z && z!=x)) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                return res; 
            }
        }
    }
    return {0, 0};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int y;
            cin >> y;
            a[i] = y;  
        }
        vector<int> b = solve(a, n);
        cout << b[0] << " " << b[1] << endl;
    }
}
