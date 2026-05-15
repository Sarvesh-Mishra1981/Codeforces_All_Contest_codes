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
#define vvi vector<vector<ll>>
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

int main() {
    unordered_map<string,string> ones;
ones["0"]="zero";
ones["1"]="one";
ones["2"]="two";
ones["3"]="three";
ones["4"]="four";
ones["5"]="five";
ones["6"]="six";
ones["7"]="seven";
ones["8"]="eight";
ones["9"]="nine";
ones["10"]="ten";
ones["11"]="eleven";
ones["12"]="twelve";
ones["13"]="thirteen";
ones["14"]="fourteen";
ones["15"]="fifteen";
ones["16"]="sixteen";
ones["17"]="seventeen";
ones["18"]="eighteen";
ones["19"]="nineteen";

unordered_map<string,string> tens;

tens["2"] = "twenty";
tens["3"] = "thirty";
tens["4"] = "forty";
tens["5"] = "fifty";
tens["6"] = "sixty";
tens["7"] = "seventy";
tens["8"] = "eighty";
tens["9"] = "ninety";

      string s;
      cin>>s;
      string ans;
        if(ones.count(s)){
        cout << ones[s];
    }
    else if(s.length()==2){
        string first(1,s[0]);
        string second(1,s[1]);

        if(s[1]=='0'){
            cout << tens[first];
        }
        else{
            cout << tens[first] + "-" + ones[second];
        }
    }
}