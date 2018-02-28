#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> v;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;

		v.push_back(a);
	}
	sort(v.begin(),v.end());

	for(int i=n-1;i>=0;i--){
		if(v[i]<0){cout<<v[i]<<endl;break;}
		if(floor(sqrt((float)v[i])) != ceil(sqrt((float)v[i]))){cout<<v[i]<<endl;break;}
	}
}