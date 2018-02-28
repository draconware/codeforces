#include<bits/stdc++.h>
using namespace std;

vector<int> res[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n,k,d;
	cin>>n>>k>>d;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		res[a%d].push_back(a);
	}

	for(int i=0;i<d;i++){
		if(res[i].size() >= k){
			cout<<"Yes"<<endl;
			for(int j=0;j<k;j++){cout<<res[i][j]<<" ";}cout<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}