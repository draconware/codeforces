#include<bits/stdc++.h>
using namespace std;

pair<int,int> res[100009];

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
	if(n == 100099){cout<<"madarchod"<<endl;}

	vector<pair<int,int> > a,b;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(y==1){
			a.push_back(make_pair(x,i));
		}else{
			b.push_back(make_pair(x,i));
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	for(int i=0;i<(int)a.size();i++){
		res[a[i].second] = make_pair(1,i+2);
	}

	int l=0,r=1;

	for(int i=0;i<(int)b.size();i++){
		int x = b[i].first;
		int idx = b[i].second;

		while(r<n-1 && a[r].first > x){
			l=0;r++;
		}
	//	cout<<i<<" "<<r<<endl;
		if(r>=n-1){cout<<"-1"<<endl;return 0;}
		res[idx] = make_pair(res[a[l].second].second,res[a[r].second].second);
		if((l+1) >= r){
			l=0;r++;
		}else{
			l++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
}
