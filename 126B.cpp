#include<bits/stdc++.h>
using namespace std;

string s;
map<string,bool> prefix,suffix;
int n;
vector<string> v;
vector<pair<int,int> > v_;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>s;

	n = (int)s.length();
	string temp;
	for(int i=0;i<n;i++){
		suffix[s.substr(i,n-1)]=true;
	}
	int k=0;
	for(int i=0;i<n;i++){
		temp.push_back(s[i]);
		prefix[temp]=true;
		if(suffix[temp]){v.push_back(temp);v_.push_back(make_pair((int)temp.size(),k));k++;}
	}
	bool flag=false;
	sort(v_.begin(),v_.end());

	for(int i=0;i<v.size();i++){
		string temp = v[v_[i].second];
		size_t fnd = s.find(temp,1,n-2);
		if(fnd < n-1){cout<<temp<<endl;return 0;}
	}
	cout<<"Just a legend"<<endl;
}