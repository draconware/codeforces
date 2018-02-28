#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int v;
	cin>>v;

	int arr[10];
	for(int i=1;i<=9;i++){
		cin>>arr[i];
	}
	int idx=1;
	for(int i=1;i<=9;i++){
		if(arr[idx] > arr[i]){
			idx=i;
		}
	}
	int len = v/arr[idx];
	if(len==0){cout<<"-1"<<endl;}
	else{
		for(int i=0;i<len;i++){
			int x = v%arr[idx];
			for(int j=9;j>=idx;j--){
				if(arr[j]-arr[idx] <= x){
					cout<<j;
					v-=(arr[j]-arr[idx]);
					break;
				}
			}
		}
		cout<<endl;
	}
}