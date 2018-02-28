#include<bits/stdc++.h>
using namespace std;

int f(int n){
	if(n<=0){return 0;}
	int res=0;
	while(n>0){
		res+=(n%10);
		n/=10;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,flag=0;
	cin>>n;

	vector<int> v;
	for(int i=1;i<=81;i++){
		if(f(n-i) == i){flag=1;v.push_back(n-i);}
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;

	if(v.size()>0){for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;}
}