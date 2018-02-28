#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k,m;
	cin>>n>>k;

	string s;
	cin>>s;
	m=s.length();

	bool mark[30];
	int cnt[30];
	memset(cnt,0,sizeof(cnt));
	memset(mark,0,sizeof(mark));
	bool flag=true;
	for(int i=9;i<m;i++){
		cnt[s[i]-'A']++;
	}
	for(int i=0;i<m;i++){
		if(!mark[s[i]-'A'] && k==0){flag=false;break;}
		if(!mark[s[i]-'A']){
			mark[s[i]-'A']=true;
			k--;
			//cnt[s[i]-'A']--;
		}
		cnt[s[i]-'A']--;
		if(cnt[s[i]-'A'] == 0){mark[s[i]-'A']=false;k++;}
	}
	if(flag){cout<<"NO"<<endl;}
	else{cout<<"YES"<<endl;}
}