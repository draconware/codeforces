#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string t,s;
	cin>>s;

	int ans = 0;
	int n = (int)s.length();
	int suma[n+1],sumb[n+1];
	memset(suma,0,sizeof(suma));
	memset(sumb,0,sizeof(sumb));


	for(int i=1;i<=n;i++){
		if(s[i-1]=='a'){suma[i]++;}
		else{sumb[i]++;}
		suma[i]+=suma[i-1];sumb[i]+=sumb[i-1];
	}

	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans = max(ans,suma[i]+sumb[j]-sumb[i]+suma[n]-suma[j]);
		}
	}
	cout<<ans<<endl;
}