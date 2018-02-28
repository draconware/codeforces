#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	char s[300009];
	scanf("%s",s);

	int n = strlen(s);
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=s[i]-'0';
	}

	LL ans=0;
	for(int i=0;i<n;i++){
		if(arr[i]%4 == 0){ans++;}
	}

	for(int i=0;i<n-1;i++){
		if((arr[i+1]+10*arr[i])%4==0){ans += (i+1);}
	}
	cout<<ans<<endl;
}