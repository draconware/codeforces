#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif

	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int cnt=0;
	for(int i=0;i<n;){
		while(i<n && arr[i] <= 2*k)
			k = max(k,arr[i++]);
		while(i<n && arr[i] > 2*k){
			k*=2;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}