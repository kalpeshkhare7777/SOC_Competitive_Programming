#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int t;cin>>t;
	long long n,b,s,k,ans;
	while(t--) {
		cin>>n>>k>>b>>s;
		if(s>=b*k+k-1)ans=(b+1)*(k)-1;
        else ans=b*k;
		if(b*k>s||(s-ans)-(n-1)*(k-1)>0) {cout<<"-1\n";continue;}
		cout<<ans<<" ",s-=ans;
		while(--n) if(s>=k-1)cout<<k-1<<" ",s-=k-1;
			else cout<<s<<" ",s=0;
		cout<<"\n";
	}
	return 0;
}