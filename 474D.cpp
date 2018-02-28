#include<bits/stdc++.h>
using namespace std;

long long int M =1000000007;

long long int val[100025],k;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif 

	long long t;
	cin>>t>>k;

	val[0]=0;
	if(k==1){val[1]=2;}
	else{val[1]=1;}

	for(long long i=2;i<100025;i++){
		val[i] = (1+val[i-1])%M;
		if(i>=k){
			val[i] = (val[i]%M+1+val[i-k]%M)%M;
		}
	}
	while(t--){
		long long x,y;
		cin>>x>>y;
		//cout<<val[x-1]<<","<<val[y]<<endl;
		cout<<(val[y]-val[x-1] + M)%M <<endl;
	}
	return 0;
}