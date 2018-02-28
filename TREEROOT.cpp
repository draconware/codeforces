#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,x,y,a=0,b=0;
		vector<pair<int,int> > v;
		vector<int> res;

		for(int i=0;i<n;i++){
			cin>>x>>y;
			v.push_back(x,y);
			a+=x;b+=y;
		}
		for(int i=0;i<n;i++){
			pair<int,int> p = v[i];
			if(sum - p.first == b){res.push_back(p.first);} 
		}
		sort(res.begin().res.end());
		for(int i=0;i<res.size();i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}