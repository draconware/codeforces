#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b,x,y;
	cin>>n>>a>>b;

	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(max(x,y) > max(a,b)){continue;}
		v.push_back(make_pair(x,y));
	}
	int temp_a,temp_b,best=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int temp=0;
			temp_a=max(a,b);temp_b=min(a,b);
			if(temp_b >= max(v[i].first,v[i].second)){
				temp_a-=min(v[i].first,v[i].second);
			}else if(temp_a == max(v[i].first,v[i].second) && temp_b >= min(v[i].first,v[i].second)){
				temp_b-=min(v[i].first,v[i].second);
			}else{
				continue;
			}
			temp += (v[i].first * v[i].second);
			int t=temp_a;
			temp_a = max(temp_a,temp_b);
			temp_b = min(t,temp_b);

			if(temp_b >= max(v[j].first,v[j].second)){
				temp_a-=min(v[j].first,v[j].second);
			}else if(temp_a == max(v[j].first,v[j].second) && temp_b >= min(v[j].first,v[j].second)){
				temp_b-=min(v[j].first,v[j].second);
			}else{
				continue;
			}
			temp += (min(v[j].first * v[j].second);)
			best = max(temp,best);
		}
	}
	cout<<best<<endl;
}