#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	LL arr[n+1];
	for(int i=1;i<=n;i++){cin>>arr[i];}

	LL b[n+1];
	for(int i=1;i<n;i++){
		b[i] = abs(arr[i]-arr[i+1]);
	}
	LL best=0,sum=0;
	int i=1;

	while(i<n){
		if(i%2 == 1){
			sum+=b[i];
			best = max(best,sum);
		}else{
			sum-=b[i];
			if(sum<0){sum=0;}
		}
		i++;
	}
	i=1;sum=0;
	while(i<n){
		if(i%2 == 0){
			sum+=b[i];
			best = max(best,sum);
		}else{
			sum-=b[i];
			if(sum<0){sum=0;}
		}
		i++;
	}
	cout<<best<<endl;
}