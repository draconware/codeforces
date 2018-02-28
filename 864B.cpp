#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;cin>>n;
	string s;cin>>s;

	string res;
	res.push_back(s[0]);
	for(int i=1;i<n;i++){
		if(s[i-1]!=s[i]){res.push_back(s[i]);}
	}
	//cout<<res<<endl;
	n = (int)res.length();
	int ans=0;
	for(int i=0;i<n;i++){
		if(res[i]>='A' && res[i]<='Z'){continue;}
		int temp=0;
		for(int j=i;j<n;j++){
			if(res[j]>='a' && res[j]<='z'){temp++;}
			else{break;}
		}
		//cout<<temp<<endl;
		ans = max(ans,temp);
	}
	cout<<ans<<endl;
}