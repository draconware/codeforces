#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string s;
	int k;
	cin>>s>>k;

	if(s.length() < k){cout<<"impossible"<<endl;}
	else{
		int dist=0;
		bool mark[30];
		memset(mark,0,sizeof(mark));
		for(int i=0;i<s.length();i++){
			if(!mark[s[i]-'a']){dist++;}
			mark[s[i]-'a']=true;
		}
		if(dist >= k){cout<<"0"<<endl;}
		else{cout<<k-dist<<endl;}
	}
}