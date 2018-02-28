#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	string t,s;
	cin>>t>>s;

	bool mark[30],flag=false;
	memset(mark,0,sizeof(mark));
	for(int i=0;i<t.size();i++){
		mark[t[i]-'a']=true;
	}
	int n,m;
	n=s.size();
	for(int i=0;i<n;i++){if(s[i]=='*'){flag=true;break;}}

	int c;
	cin>>c;
	while(c--){
		bool ans=true;
		string x;
		cin>>x;
		int y = x.size();
		
		if(flag){
			int j=0;
			for(int i=0;i<y;i++){
				if(s[i]==)
			}
		}else{
			for(int i=0;i<y;i++){
				if(s[i]=='?'){
					if(!mark[x[i]-'a']){ans=false;break;}
				}
			}
		}
		if(ans){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
	return 0;
}