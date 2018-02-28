#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,idx=-1;
	cin>>n;

	vector<pair<string,vector<int> > > v;
	string c;
	vector<int> temp;
	for(int i=0,x,y,z;i<n;i++){
		cin>>c>>x;z=c.size();
		while(x--){
			cin>>y;
			temp.push_back(y);
			idx = max(idx,y + z -1);
		}
		v.push_back(make_pair(c,temp));
		temp.clear();
	}
	string res;
	//cout<<idx<<endl;
	for(int i=0;i<idx;i++){
		res.push_back('.');
	}
	for(int i=0;i<n;i++){
		string x = v[i].first;
		vector<int> y = v[i].second;

		for(int j=0;j<y.size();j++){
			int z = y[j] -1 + x.length();
			for(int k=y[j]-1,p=0;k<z;k++,p++){
				res[k]=x[p];
				//cout<<k<<","<<res[k]<<endl;
			}
		}
	}
	for(int i=0;i<idx;i++){
		if(res[i]=='.'){res[i]='a';}
	}
	cout<<res<<endl;
}