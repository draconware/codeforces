#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif

	LL n;
	cin>>n;

	LL arr[n],maxi=0;
	LL val[100009];
	memset(val,0,sizeof(val));

	for(LL i=0;i<n;i++){
		cin>>arr[i];
		val[arr[i]]++;
		maxi = max(maxi,arr[i]);
	}
	//cout<<maxi<<endl;
	LL f[maxi+9];
	f[0]=0;f[1]=val[1];
	for(LL i=2;i<=maxi;i++){
		f[i] = max(f[i-1],f[i-2]+i*val[i]);
	}
	cout<<f[maxi]<<endl;
}