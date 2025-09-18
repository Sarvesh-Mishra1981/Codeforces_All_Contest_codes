#include<iostream>
#include<vector>
using namespace std;
bool solve(vector<int>& a,vector<int>& b,int sum){
    for(int i=(b[0]-1);i<b[1];i++){
        sum+=b[2]-a[i];
    }
    if(sum%2==1) return true;
    else return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        int sum=0;
            for(int i=0;i<n;i++){
                cin>>a[i];
                sum+=a[i];
            }
        while(q--){
            vector<int> q(3);
            for(int i=0;i<3;i++){
                cin>>q[i];
            }
            if(solve(a,q,sum)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}
