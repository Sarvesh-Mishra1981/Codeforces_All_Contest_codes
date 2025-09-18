#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<unordered_set>
#include<algorithm>
#define ll long long 
using namespace std;
bool solve(string& s,int n){
    unordered_set<char> m;
    m.insert(s[0]);
    m.insert(s[n-1]);
    bool flag=false;
    for(int i=1;i<n-1;i++){
        if(m.find(s[i])!=m.end()){
            flag=true;
        }
        m.insert(s[i]);
    }
    return flag;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(solve(s,n)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}