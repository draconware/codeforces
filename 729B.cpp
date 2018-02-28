#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;

	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int right[n][m];
	memset(right,0,sizeof(right));
	for(int i=0;i<n;i++){
		right[i][m-1]=arr[i][m-1];
		for(int j=m-2;j>=0;j--){
			right[i][j] = right[i][j+1]+arr[i][j];
		}
	}
	int left[n][m];
	memset(left,0,sizeof(left));
	for(int i=0;i<n;i++){
		left[i][0]=arr[i][0];
		for(int j=1;j<m;j++){
			left[i][j]=left[i][j-1]+arr[i][j];
		}
	}
	int down[n][m];
	memset(down,0,sizeof(down));
	for(int i=0;i<m;i++){
		down[n-1][i]=arr[n-1][i];
		for(int j=n-2;j>=0;j--){
			down[j][i] = down[j+1][i]+arr[j][i];
		}
	}
	int up[n][m];
	memset(up,0,sizeof(up));
	for(int i=0;i<m;i++){
		up[0][i]=arr[0][i];
		for(int j=1;j<n;j++){
			up[j][i]=up[j-1][i]+arr[j][i];
		}
	}

	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0){
				if(left[i][j]>0){ans++;}
				if(right[i][j]>0){ans++;}
				if(down[i][j]>0){ans++;}
				if(up[i][j]>0){ans++;}
			}
		}
	}
	cout<<ans<<endl;
}