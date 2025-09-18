#include<iostream>
#include<vector>
using namespace std;

bool Isallzero(vector<int>& a,int n){
    for(int i=0;i<n;i++){
        if(a[i]>0) return false;
    }
    return true;
}

int solve(vector<int>& a,int n){
    int res=0;
    vector<int> b(10,0);
    b[0]=3;
    b[1]=1;
    b[2]=2;
    b[3]=1;
    b[5]=1;

    for(int i=0;i<n;i++){
        if(b[a[i]]>0){
            b[a[i]]--;
        }
        if(Isallzero(b,10)) {
            res=i+1;   
            break;
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<solve(a,n)<<endl;
    }
}
