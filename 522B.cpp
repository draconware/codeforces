#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int b[n],h[n],p[n],s[n];
	memset(h,0,sizeof(p));
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++){
		cin>>b[i]>>h[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=b[i];
	}

	p[0]=h[0];
	for(int i=1;i<n;i++){
		p[i] = max(p[i-1],h[i]);
	}
	s[n-1]=h[n-1];
	for(int i=n-2;i>=0;i--){
		s[i] = max(s[i+1],h[i]);
	}
	//for(int i=0;i<n;i++){cout<<p[i]<<" ";}cout<<endl;
	//for(int i=0;i<n;i++){cout<<s[i]<<" ";}cout<<endl;
	for(int i=0;i<n;i++){
		int ans = (sum-b[i]);
		if(i-1<0){cout<<ans*(s[i+1])<<" ";}
		else if(i+1==n){cout<<ans*p[i-1]<<" ";}
		else{
			cout<<ans*(max(s[i+1],p[i-1]))<<" ";
		}
	}
	cout<<endl;
}