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

	vector<int> v;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		v.push_back(a);
	}

	int i=1,j=1000000,ans=0,l=0,r=n-1;

	while(n>0){
		if(i == v[l]){l++;n--;}
		if(j == v[r]){r--;n--;}
		i++;j--;ans++;
	}
	cout<<ans-1<<endl;
}