#include<bits/stdc++.h>
using namespace std;

int res[1000009];

int f(int x){
	if(res[x]>0){return res[x];}
	int y=x,p=1;
	while(y>0){
		if((y%10) != 0){p=p*(y%10);}
		y/=10;
	}
	res[x] = f(p);
	return res[x];
}

vector<int> G[11];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(res,0,sizeof(res));
	for(int i=1;i<10;i++){
		res[i] = i;
	}
	for(int i=10;i<1000001;i++){
		res[i] = f(i);
	}

	int t;
	cin>>t;

	for(int i=1;i<1000001;i++){
		G[res[i]].push_back(i);
	}

	while(t--){
		int l,r,k;
		cin>>l>>r>>k;

		vector<int>::iterator it = lower_bound(G[k].begin(),G[k].end(),l);
		int i = it - G[k].begin();
		it = upper_bound(G[k].begin(),G[k].end(),r);
		int j = it - G[k].begin();
		cout<<(j-i)<<endl;
	}
}