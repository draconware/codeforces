#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<LL> v;
int m,n;
LL val[5009][5009];

LL dp(int i,int k){
	//cout<<i<<" "<<k<<endl;
	if(k==0 || i>n){return 0;}
	if(val[i][k] != -1){return val[i][k];}

	LL sum=0;
	sum = max(sum,dp(i+1,k));
	if(i+m-1 <= n){
		//if(i==4){cout<<"executed"<<endl;}
		sum = max(sum,dp(i+m,k-1)+v[i+m-1]-v[i-1]);
	}
	val[i][k]=sum;
	//cout<<i<<","<<k<<" "<<val[i][k]<<endl;
	return val[i][k];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	memset(val,-1,sizeof(val));
	int k;
	cin>>n>>m>>k;

	LL x=0,y;
	v.push_back(0);
	for(int i=0;i<n;i++){
		cin>>y;
		x+=y;
		v.push_back(x);
	}
	LL ans = dp(1,k);
	cout<<ans<<endl;
}