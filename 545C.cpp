#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif 

	int n,ans=0;
	cin>>n;

	vector<pair<int,int> > v;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	if(n<=2){cout<<n<<endl;}
	else{
		ans++;
		int l=v[0].first,h=v[2].first;
		for(int i=1;i<n-1;i++){
			bool flag=false;
			h=v[i+1].first;
			if(v[i].first-v[i].second > l){ans++;}
			else if(v[i].first+v[i].second < h){ans++;flag=true;}
			//if(v[i].first-v[i].second > l){ans++;}
			if(flag){l = v[i].first+v[i].second;}
			else{l = v[i].first;}
		}
		
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}