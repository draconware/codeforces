#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	vector<int> v(m);
	for(int i=0;i<m;i++){
		cin>>v[i];
	}
	int ans=INT_MAX;
	sort(v.begin(),v.end());
	for(int i=0;i<=m-n;i++){
		ans = min(ans,v[n-1+i]-v[i]);
	}
	cout<<ans<<endl;
}