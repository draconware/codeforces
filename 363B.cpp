#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,k;
	cin>>n>>k;

	int arr[n],sum[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	sum[0]=arr[0];
	for(int i=1;i<n;i++){
		sum[i] = arr[i]+sum[i-1];
	}
	int best = sum[k-1],x=1;
	for(int i=k;i<n;i++){
		//cout<<best<<","<<sum[i]-sum[i-k]<<endl;
		if(best > sum[i]-sum[i-k]){
			best = sum[i]-sum[i-k];
			x = i-k+2;
		}
	}
	cout<<x<<endl;
}