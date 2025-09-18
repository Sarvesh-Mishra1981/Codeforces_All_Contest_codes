#include<iostream>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,k;
  cin>> n >> m >> k;
    string s;
  cin>> s;
  
  int ans=0;
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='0')
    {
      count++;
      if(count==m)
      {
        ans++;
        count=0;
        i=i+k-1;
        
      }
      

    }
    else count=0;

  }
  cout<<ans<<endl;
}


}