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

	int mini = arr[0];
	for(int i=1;i<n;i++){mini = min(mini,arr[i]);}

	vector<int> v;
	for(int i=0;i<n;i++){
		if(mini == arr[i]){v.push_back(i);}
	}

	int ans = n+1;
	n = (int)v.size();

	for(int i=1;i<n;i++){
		ans = min(ans,v[i]-v[i-1]);
	}
	cout<<ans<<endl;
}