#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}
	if(n%2==1){
		if(arr[0]%2==1 && arr[n-1]%2==1){cout<<"Yes"<<endl;}
		else{cout<<"No"<<endl;}
	}else{
		cout<<"No"<<endl;
	}
}