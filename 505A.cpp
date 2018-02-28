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
	int i=0,j=n-1;
	while(i<=j){
		if(s[i]!=s[j]){break;}
		i++;j--;
	}
	//cout<<i<<" "<<j<<endl;
	if(i>j){
		if(n&1){
			for(int a=0;a<=n/2;a++){cout<<s[a];}
			cout<<s[n/2];
			for(int a=n/2 +1;a<n;a++){cout<<s[a];}
			cout<<endl;
			return 0;
		}else{
			for(int a=0;a<n/2;a++){cout<<s[a];}
			cout<<"a";
			for(int a=n/2;a<n;a++){cout<<s[a];}
			cout<<endl;
			return 0;
		}
	}
	int l = i+1,r=j;
	while(l<=r){
		if(s[l]!=s[r]){break;}
		l++;r--;
	}
	//cout<<l<<" "<<r<<endl;
	if(l>r){
		for(int a=0;a<=j;a++){cout<<s[a];}
		cout<<s[i];
		for(int a=j+1;a<n;a++){cout<<s[a];}
		cout<<endl;
		return 0;
	}
	l = i;r = j-1;
	while(l<=r){
		if(s[l]!=s[r]){break;}
		l++;r--;
	}
	//cout<<l<<" "<<r<<endl;
	if(l>r){
		for(int a=0;a<i;a++){cout<<s[a];}
		cout<<s[j];
		for(int a=i;a<n;a++){cout<<s[a];}
		cout<<endl;
		return 0;
	}
	cout<<"NA"<<endl;
}