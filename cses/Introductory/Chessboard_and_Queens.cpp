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
#define ll  long long
#define ld  long double
#define vi  vector<ll>
#define pi  pair<ll,ll>
#define vpi vector<pi>
#define pb  push_back
#define ff  first
#define ss  second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define fd(i,s,e) for(ll i=s;i>e;i--)
#define tc  ll t;cin>>t;while(t--)
#define in(v) for(auto &x:v) cin>>x
#define out(v) for(auto &x:v) cout<<x<<" "
#define inp(v) for(auto &x:v) cin>>x.ff>>x.ss
#define Y cout<<"YES\n"
#define N cout<<"NO\n"
#define nl cout<<'\n'
#define mn3(a,b,c) min(a,min(b,c))
#define mx3(a,b,c) max(a,max(b,c))
#define hi(v) *max_element(all(v))
#define lo(v) *min_element(all(v))
#define dbg(x) cerr<<#x<<"="<<x<<'\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX;
const int Na = 2e5+5;

// -----------------------------------Lets Do IT---------------------------------------------------------------

ll val = 0;

bool isSafe(vector<string>& a, int row, int col) {
    if (a[row][col] == '*') return false;
    for (int i = 0; i < row; i++) {
        if (a[i][col] == 'Q') return false; 
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (a[i][j] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j < 8; i--, j++) {
        if (a[i][j] == 'Q') return false;
    }

    return true;
}
void solveRec(vector<string>& a, int row) {
    if (row == 8) {
        val++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (isSafe(a, row, col)) {
            a[row][col] = 'Q';
            solveRec(a, row + 1);
            a[row][col] = '.'; 
        }
    }
}

int main() {
    fast;
    vector<string> a(8);
    for (int i = 0; i < 8; i++) {
        cin >> a[i];
    }

    val = 0;
    solveRec(a, 0);
    cout << val << endl;
    return 0;
}