#include <iostream>
#include <vector>
using namespace std;
#define ll long long int
 
int main(){
  
   int t;                  cin>>t;
   while(t--){
      int n;               cin>>n;
      vector<int> a(n);
 
      bool ok=false;
      for(int i=0;i<n;i++){
         cin>>a[i];
         if(i>=a[i]-1){
            ok=true;
         }
      }
      if(ok){
         cout<<"YES"<<endl;
      }
      else{
         cout<<"NO"<<endl;
      }
   }
   return 0;
}