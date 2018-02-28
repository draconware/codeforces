#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> v;
	vector<pair<int,int> > res;

	for(int i=0,x;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	int l,h;
	set<int> s;

	for(int i=0;i<n;){
		l=i;h=i;
		bool check=false;
		while(h<n){
			s.insert(v[h]);
			if(s.size() != h-l+1){check=true;s.clear();break;}
			h++;
		}
		if(h==n && !check){
			if(res.size() > 0){
				res[res.size()-1].second = h;
				break;
			}else{
				cout<<"-1"<<endl;
				return 0;
			}
		}else{
			res.push_back(make_pair(l+1,h+1));
		}
		i=h+1;
	}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}