#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[n],q=0;
	//int val[n][n];
	//memset(val,0,sizeof(val));
	int b[n],best=INT_MIN,max_before=0;
	for(int i=0;i<n;i++){cin>>arr[i];if(arr[i]==1){q++;b[i]=-1;}else{b[i]=1;}}

	for(int i=0;i<n;i++){
		max_before+=b[i];
		best = max(best,max_before);
		if(max_before < 0){max_before=0;}
	}
	cout<<q+best<<endl;
}