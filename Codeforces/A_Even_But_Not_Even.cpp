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
#include <unordered_set>
#include <unistd.h>
#include <unordered_map>

using namespace std;

#define ll long long
#define fi(i,s,e) for(ll i=s;i<e;i++)
#define fd(i,s,e) for(ll i=s;i>=e;i--)
#define tc ll t;cin>>t;while(t--)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string solve(string& s, ll k) {

    ll oddnum = 0, evennum = 0;

    fi(i,0,k) {

        ll digit = s[i] - '0';

        if(digit % 2)
            oddnum++;
        else
            evennum++;
    }

    if(oddnum < 2)
        return "-1";

    ll last = -1;
    ll secondLast = -1;

    fd(i,k-1,0) {

        ll digit = s[i] - '0';

        if(digit % 2 == 1) {

            if(last == -1)
                last = i;

            else {
                secondLast = i;
                break;
            }
        }
    }

    if(oddnum % 2 == 0 && last == k - 1) {
        return s;
    }
    else {

        if(oddnum & 1) {
            return s.substr(0, secondLast + 1);
        } 
        else {
            return s.substr(0, last + 1);
        }
    }
}

int main() {

    fast;

    tc {

        ll k;
        cin >> k;

        string s;
        cin >> s;

        cout << solve(s, k) << endl;
    }
}