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

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<pair<int,int> > v;
		for(int i=0;i<n;i++){
			int l,r;
			cin>>l>>r;

			v.push_back(make_pair(l,r));
		}

		int res[n];
		memset(res,0,sizeof(res));
		int c=1;
		for(int i=0;i<n;i++){
			if(v[i].first>c){res[i]=v[i].first;c=v[i].first+1;}
			else if(v[i].first<=c && v[i].second>=c){res[i]=c;c++;}
			else if(v[i].second < c){res[i] = 0;}
		}

		for(int i=0;i<n;i++){cout<<res[i]<<" ";}cout<<endl;
	}
}