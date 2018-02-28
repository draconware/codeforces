#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int s[11],m[11],temp_s[11],temp_m[11];
	string ss,sm;
	cin>>ss>>sm;
	memset(s,0,sizeof(s));
	memset(m,0,sizeof(m));
	memset(temp_s,0,sizeof(temp_s));
	memset(temp_m,0,sizeof(temp_m));
	for(int i=0;i<n;i++){
		s[ss[i]-'0']++;
		m[sm[i]-'0']++;
		temp_s[ss[i]-'0']++;
		temp_m[sm[i]-'0']++;
	}
	int ans1=0,ans2=0;
	for(int i=0;i<10;i++){
		//cout<<s[i]<<" "<<m[i]<<endl;
		ans1 += min(s[i],m[i]);
		if(m[i] < s[i]){
			s[i]-=m[i];m[i]=0;
		}else{
			m[i]-=s[i];s[i]=0;
		}
		s[i+1]+=s[i];
		//m[i+1]+=m[i];
	}
	for(int i=1;i<10;i++){
		//cout<<temp_s[i]<<" "<<temp_
		ans2 += min(temp_s[i-1],temp_m[i]);
		if(temp_s[i-1] > temp_m[i]){
			temp_s[i-1]-=temp_m[i];
		}else{
			temp_s[i-1]=0;
		}
		temp_s[i]+=temp_s[i-1];
	}
	cout<<n-ans1<<"\n"<<ans2<<endl;
}