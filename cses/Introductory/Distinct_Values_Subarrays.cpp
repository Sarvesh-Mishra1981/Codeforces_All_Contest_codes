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
ll solve(ll* arr, ll N, ll K)
{

    // left and right pointers to mark the start and end of
    // the sliding window
    ll left = 0, right = 0;
    // Variable to count how many different numbers we have
    // in the window
    ll distinct_count = 0;
    // Variable to store the final result
    ll result = 0;

    // Map to keep track of how many times each number
    // appears in the window
    unordered_map<ll, ll> frequency;

    // Slide the window till the window till the right
    // pointer does not reach the end of the array
    while (right < N) {
        // Check if the current number is new or if its
        // count is zero
        if (frequency.find(arr[right]) == frequency.end()
            || frequency[arr[right]] == 0)
            distinct_count++;

        // Update the count of the current number
        frequency[arr[right]]++;

        // If there are more than K distinct numbers, shrink
        // the window from the left
        while (distinct_count > K) {
            // Decrease the count of the number going out of
            // the window
            frequency[arr[left]]--;
            // If its count becomes zero, then there will be
            // one less distinct number in the window
            if (frequency[arr[left]] == 0)
                distinct_count--;
            // Move the left pointer to the right to shrink
            // the window
            left++;
        }

        // Calculate the number of subarrays that end at the
        // current position
        result += right - left + 1;

        // Move the right edge of the window to the right to
        // expand it
        right++;
    }
    // Return the result
    return result;
}

int main() {
    fast;
        ll n; cin>>n;
        vi a(n); in(a);
        cout<<solve(a,n)<<endl;
}