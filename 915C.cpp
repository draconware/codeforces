#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;

	int n = (int)a.length();
	int m = (int)b.length();

	int i=0,j=0;

	vector<int> u;
	vector<int> v;
	for(int i=0;i<n;i++){
		u.push_back(a[i]-'a');
	}
	for(int i=0;i<m;i++){
		v.push_back(b[i]-'a');
	}
	sort(u.begin(),u.end());

	if(n<m){
		for(int i=n-1;i>=0;i--){cout<<u[i];}cout<<endl;
	}
}