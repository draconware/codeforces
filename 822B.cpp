#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	string s,t;
	cin>>s>>t;

	//cout<<s<<" "<<t<<endl;
	vector<int> res;
	int best=n+1;
	for(int i=0;i<=m-n;i++){
		vector<int> temp;
		int comp=0;
		for(int j=i;j<n+i;j++){
			if(s[j-i] != t[j]){comp++;temp.push_back(j-i+1);}
		}
		if(comp<best){res.clear();res=temp;best=comp;}
		//cout<<best<<endl;
	}
	cout<<best<<endl;
	if(best>0){
		for(int i=0;i<best;i++){cout<<res[i]<<" ";}cout<<endl;
	}
}