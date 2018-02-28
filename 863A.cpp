#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	string s;
	cin>>s;

	int n = (int)s.length();
	int i=n-1;

	while(s[i]=='0' && i>=0){
		i--;
	}
	bool flag=true;
	for(int j=0;j<=i;j++){
		if(s[j] != s[i-j]){flag=false;}
	}
	if(flag){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
}