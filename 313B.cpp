#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string s;
	cin>>s;

	int n=s.length();
	int val[n];

	val[0]=0;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1]){val[i] = val[i-1]+1;}
		else{val[i]=val[i-1];}
	}
	int m,x,y;
	cin>>m;

	while(m--){
		cin>>x>>y;
		cout<<val[y-1]-val[x-1]<<endl;
	}
	return 0;
}