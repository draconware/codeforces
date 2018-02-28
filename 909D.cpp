#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin>>s;
	int n = (int)s.length();

	vector<pair<int,char> > v,temp;
	int c=1;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1]){c++;}
		else{
			v.push_back(make_pair(c,s[i-1]));
			c=1;
		}
	}

	v.push_back(make_pair(c,s[n-1]));
	n = (int)v.size();
	int ans=0;
	while(n>1){
		ans++;
		for(int i=0;i<n;i++){
			if(i==0 || i==n-1){v[i].first = max(v[i].first-1,0);}
			else{v[i].first = max(v[i].first-2,0);}
		}
		temp.clear();
		for(int i=0;i<n;i++){
			if(v[i].first > 0){temp.push_back(v[i]);}
		}

		n = (int)temp.size();

		v.clear();
		if(n==0){break;}
		int c=temp[0].first;
		for(int i=1;i<n;i++){
			if(temp[i].second == temp[i-1].second){c += temp[i].first;}
			else{v.push_back(make_pair(c,temp[i-1].second));c=temp[i].first;}
		}
		v.push_back(make_pair(c,temp[n-1].second));
		n = (int)v.size();
	}
	cout<<ans<<endl;
}