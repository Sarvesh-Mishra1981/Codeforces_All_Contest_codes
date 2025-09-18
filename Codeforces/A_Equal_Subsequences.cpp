#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long 
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            if(i<k){
                a[i]=1;
            }
            else{
                a[i]=0;
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i];
        }
        cout<<endl;
    }
}