#include<bits/stdc++.h>
using namespace std;

vector<int> res[60];

int main(){
	int x,n,k;
	cin>>n>>k;

	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	bool mark[35009];
	memset(mark,0,sizeof(mark));
	int m=1,i=0,p;
	while(m<k){
		for(int p=i;p<n;p++){
			if(!mark[v[p]]){res[m].push_back(v[p]);}
			else{}
		}
	}
	if(i<n){
		for(int j=i;j<n;j++){
			res[m].push_back(v[j]);
		}
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<res[i].size();j++){
			if(!mark[res[i][j]]){ans++;mark[res[i][j]]=true;}
		}
		for(int j=0;j<res[i].size();j++){
			mark[res[i][j]]=false;
		}
	}
	cout<<ans<<endl;
}