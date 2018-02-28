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
	bool mark[n];
	for(int i=0;i<n;i++){cin>>arr[i];arr[i]--;}

	for(int i=0;i<n;i++){
		if(arr[arr[arr[i]]] == i){cout<<"YES"<<endl;return 0;}
	}
	cout<<"NO"<<endl;
}