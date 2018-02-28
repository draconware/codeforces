#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<int> res;
	while(n>0){
		int k=n,m=0;
		vector<int> v;
		while(k>0){
			v.push_back(min(1,k%10));
			k/=10;
		}
		int size = v.size();
		for(int i=size-1;i>=0;i--){
			m = m*10+v[i];
		}
		n-=m;
		res.push_back(m);
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	if(res.size() > 0){cout<<endl;}
}