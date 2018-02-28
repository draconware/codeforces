#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n;
	cin>>n;

	map<string,bool> m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(m[s]){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
		m[s]=true;
	}
	return 0;
}