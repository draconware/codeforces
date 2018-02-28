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
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max_len=1,len=1;
	for(int i=0;i<n-1;i++){
		if(arr[i]<arr[i+1]){
			len++;
		}else{
			max_len = max(max_len,len);
			len=1;
		}
	}
	max_len = max(max_len,len);
	cout<<max_len<<endl;
}