#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,c=0;
	cin>>n;

	vector<pair<long long,pair<int,int> > > v;
	for(int i=0,x,y;i<n;i++){
		cin>>x>>y;
		long long z = (abs(x)+abs(y));
		v.push_back(make_pair(z,make_pair(x,y)));
		if(a && b){c+=6;}
		else{c+=4;}
	}
	sort(v.begin(),v.end());
	cout<<c<<endl;
	for(int i=0;i<n;i++){
		cout<<"1 ";
		if(v[i].second.first != 0){
			cout<<abs(v[i].second.first)<<" ";
			if(v[i].second.first > 0){
				cout<<"R"<<endl;
			}else{
				cout<<"L"<<endl;
			}
		}
		if(v[i].second.second != 0){
			cout<<abs(v[i].second.second)<<" ";
			if(v[i].second.second > 0){
				cout<<"U"<<endl;
			}else{
				cout<<"D"<<endl;
			}
		}
		cout<<"2"<<endl;
		if(v[i].second.first != 0){
			cout<<abs(v[i].second.first)<<" ";
			if(v[i].second.first > 0){
				cout<<"L"<<endl;
			}else{
				cout<<"R"<<endl;
			}
		}
		if(v[i].second.second != 0){
			cout<<abs(v[i].second.second)<<" ";
			if(v[i].second.second > 0){
				cout<<"D"<<endl;
			}else{
				cout<<"U"<<endl;
			}
		}
		cout<<"3"<<endl;
	}
	return 0;
}