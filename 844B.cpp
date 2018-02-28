#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

LL power(LL y){
	LL res=1,x=2;
	while(y>0){
		if(y%2 == 1){res*=x;}
		y/=2;
		x*=x;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	LL ans=0;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		LL x=0,y=0;
		for(int j=0;j<m;j++){
			if(arr[i][j]==1){x++;}
			else{y++;}
		}
		ans = ans + power(x) + power(y) -2;
	}
	for(int i=0;i<m;i++){
		LL x=0,y=0;
		for(int j=0;j<n;j++){
			if(arr[j][i]==1){x++;}
			else{y++;}
		}
		ans = ans + power(x) + power(y) -2;
	}
	ans = ans - (LL)(n*m);
	cout<<ans<<endl;
}