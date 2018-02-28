#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,d;
	cin>>n>>d;

	vector<int> v;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());

	int maxi = INT_MAX;
	for(int i=0;i<n;i++){
		int x = v[i];
		vector<int>::iterator it = upper_bound(v.begin(),v.end(),v[i]+d);

		int j = it - v.begin();
		int res = n - j;
		res = res + i;

		maxi = min(maxi,res);
	}
	cout<<maxi<<endl;
}