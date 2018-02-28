#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int m,n;
	cin>>m>>n;

	int arr[m+1][n+1];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=1;i<=n;i++){
		arr[0][i]+=arr[0][i-1];
	}
	cout<<arr[0][n]<<" ";
	for(int i=1;i<m;i++){
		arr[i][0]+=arr[i-1][0];
		for(int j=1;j<=n;j++){
			arr[i][j]+=arr[i][j-1];
			if(arr[i][j-1]<arr[i-1][j]){
				arr[i][j]+=(arr[i-1][j]-arr[i][j-1]);
			}
		}
		cout<<arr[i][n]<<" ";
	}
	cout<<endl;
}