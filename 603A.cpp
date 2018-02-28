#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n;
	cin>>n;

	string s;
	cin>>s;
	int ans = 1;
	char c = s[0];
	for(int i=1;i<n;i++){
		if(s[i]!=c){ans++;c=s[i];}
	}
	int x=0;
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1]){x++;}
	}
	cout<<ans+min(2,x)<<endl;
}