#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL M = 1000000007;
int n;
int arr[5009];
LL dp[5009][5009];

LL f(int idx,int lev){
	if(idx==n){return 1;}
	if(dp[idx][lev]!=-1){return dp[idx][lev];}

	LL sum=0;
	if(arr[idx-1]==0){
		sum = f(idx+1,lev);
		if(lev){sum = (sum + f(idx,lev-1))%M;}
	}else{
		sum = f(idx+1,lev+1);
	}
	dp[idx][lev]=sum;
	return sum;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char a;cin>>a;
		if(a=='s'){arr[i]=0;}
		else{arr[i]=1;}
	}
	memset(dp,-1,sizeof(dp));
	LL ans = f(1,0);
	cout<<ans<<endl;
}