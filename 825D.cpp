#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif

	string s,t;
	cin>>s>>t;

	vector<int> a0(26,0),a1(26,0);
	int n=s.length(),m=t.length(),q=0;
	for(int i=0;i<n;i++){
		if(s[i]=='?'){q++;}
		else{a0[s[i]-'a']++;}
	}
	for(int i=0;i<m;i++){
		a1[t[i]-'a']++;
	}
	int l=0,h=n-m+1,x;
	while(l<=h){
		int m = (l+h)/2,q0=q;
		for(int i=0;i<26;i++){
			if(a0[i] < m*a1[i]){q0-=(a1[i]*m - a0[i]);}
		}
		if(q0>=0){x=m;l = m+1;}
		else{h = m-1;}
		//cout<<x<<" "<<l<<","<<h<<endl;
	}
	for(int i=0;i<26;i++){
		a1[i] = a1[i]*x;
	}
	int j=0;
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			if(j>=25){s[i]='z';}
			else{
				while(j<25 && a0[j]>=a1[j]){j++;}
				s[i] = 'a'+j;
				a0[j]++;
			}
		}
	}
	cout<<s<<endl;
}