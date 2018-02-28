#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	vector<int> v;
	int a[n],res[n];
	for(int i=0,x;i<n;i++){
		cin>>x;
		v.push_back(x);
		a[i]=x;
	}

	sort(v.begin(),v.end());
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==v[j]){res[i]=j;}
		}
	}

	for(int i=0;i<n;i++){
		cout<<v[(res[i]+n-1)%n]<<" ";
	}
	cout<<endl;
}