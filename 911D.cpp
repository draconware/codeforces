#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}
	int ans=0;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){ans^=1;}
		}
	}

	int q;
	cin>>q;

	while(q--){
		int a,b;
		cin>>a>>b;
		int c = (b-a)*(b-a+1);
		c/=2;
		//cout<<c<<" ";
		if(c&1){ans^=1;}

		if(ans){cout<<"odd"<<endl;}
		else{cout<<"even"<<endl;}
	}
}