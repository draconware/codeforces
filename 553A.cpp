#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL M = 1000000007;

LL val[1009][1009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	for(int i=0;i<1009;i++){
		val[i][0]=1;val[i][i]=1;
	}
	for(int i=2;i<1009;i++){
		for(int j=1;j<i;j++){
			val[i][j] = (val[i-1][j-1]+val[i-1][j])%M;
		}
	}
	int n;
	cin>>n;

	LL res=1;
	int sum=0;
	for(int i=0,x;i<n;i++){
		cin>>x;
		res = (res*val[sum+x-1][x-1])%M;
		sum+=x;
		//cout<<res<<" ";
	}
	cout<<res<<endl;
}