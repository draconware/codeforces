#include<bits/stdc++.h>
using namespace std;

map<string,string> mp;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		mp[b] = a;
	}

	for(int i=0;i<m;i++){
		string a,b;
		cin>>a>>b;

		int len = (int)b.length();
		string c;
		for(int j=0;j<len;j++){
			if(b[j] != ';'){c.push_back(b[j]);}
		}
		cout<<a<<" "<<b<<" #"<<mp[c]<<endl;
	}
}