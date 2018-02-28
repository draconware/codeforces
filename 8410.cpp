#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	int cnt[30];
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++){
		cnt[s[i]-'a']++;
	}
	bool flag=true;
	for(int i=0;i<30;i++){
		if(cnt[i]>k){flag=false;break;}
	}
	if(flag){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}