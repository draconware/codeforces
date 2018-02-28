#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	int mark[30];
	for(int i=0;i<30;i++){mark[i]=0;}

	int got=-1;
	int ans=0;
	for(int i=0;i<n;i++){
		int cnt=0,cnt2=0;
		for(int j=0;j<26;j++){if(mark[j]==1){cnt++;got=j;}if(mark[j]==-1){cnt2++;}}
		if(cnt2==25 && cnt==0){
			for(int j=0;j<26;j++){
				if(mark[j]==0){got=j;}
			}
			cnt=1;
		}
		//cout<<cnt<<endl;

		string s1,s2;
		cin>>s1>>s2;
		//cout<<s1<<" "<<s2<<endl;
		if(i==n-1){continue;}

		if(s1[0]=='.'){
			for(int j=0;j<(int)s2.length();j++){
				mark[s2[j]-'a']=-1;
			}
		}else if(s1[0]=='!'){
			if(cnt==1){ans++;}
			else if(cnt==0){
				bool temp[30];
				for(int j=0;j<30;j++){temp[j]=false;}
				for(int j=0;j<(int)s2.length();j++){temp[s2[j]-'a']=true;}
				for(int j=0;j<26;j++){
					if(temp[j] && mark[j]>=0){mark[j]=1;}
					else{
						mark[j]=-1;
					}
				}
			}else{
				bool temp[30];
				memset(temp,0,sizeof(temp));
				for(int j=0;j<(int)s2.length();j++){temp[s2[j]-'a']=true;}
				for(int j=0;j<26;j++){
					if(mark[j]==1 && temp[j]){

					}else{
						mark[j]=-1;
					}
				}
			}
		}else{
			mark[s2[0]-'a']=-1;
			if(cnt==1){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
