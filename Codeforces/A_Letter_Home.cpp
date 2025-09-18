#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long 
using namespace std;
int solve(vector<int>& a,int n ,int s){
 if(s<a[n-1] && s>a[0]){
    int diff1=s-a[0];
    int diff2=a[n-1]-s;
    int ans1=min((diff1)*2+diff2,diff2*2+diff1);
    return ans1;
 }
 else if(s>=a[n-1]){
    int ans=s-a[0];
    return ans;
 }
 else {
    return (a[n-1]-s);
 }
 return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<solve(a,n,s)<<endl;
    }
}