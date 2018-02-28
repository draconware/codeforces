#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[n][5];
	for(int i=0;i<n;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4];
	}
	int square[n];
	memset(square,0,sizeof(square));
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			square[i]+=(arr[i][j]*arr[i][j]);
		}
	}
	//for(int )
	int product[n][n];
	memset(product,0,sizeof(product));
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<5;k++){
				product[i][j] += (arr[i][k]*arr[j][k]);
			}
			product[j][i]=product[i][j];
		}
	}

	vector<int> res;
	for(int i=0;i<n;i++){
		bool flag=true;
		for(int j=0;j<n;j++){
			if(j==i){continue;}
			for(int k=0;k<n;k++){
				if(k==i || k==j){continue;}
				if(square[i] > product[i][j]+product[i][k]-product[j][k]){flag=false;break;}
			}
			if(!flag){break;}
		}
		if(flag){res.push_back(i+1);}
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
}