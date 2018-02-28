#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL ncr[1009][1009];
LL M = (LL)(1e9+7);
bool mark[1009];
vector<int> G[1009];
int steps[1009];

int count(int s){
	int x = 1;
	int res=0;
	while(x<s){x*=2;}
	for(int i=x;i>0;i/=2){
		if(s>=i){s-=i;res++;}
	}
	return res;
}

void dfs(int s){
	mark[s]=true;
	if(s==1){steps[s]=0;}
	int x = count(s);
	if(mark[x]){
		steps[s] = 1+steps[x];
	}else{
		mark[x]=true;
		dfs(x);
		steps[s] = 1+steps[x];
	}
}

void pre(){
	for(int i=0;i<1009;i++){
		ncr[i][i] = 1;
		ncr[i][0] = 1;
	}
	for(int i=2;i<1009;i++){
		for(int j=1;j<i;j++){
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%M;
		}
	}
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=1005;i++){
		if(!mark[i]){dfs(i);}
	}

	for(int i=1;i<=1005;i++){
		G[steps[i]].push_back(i);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pre();

	string s;
	cin>>s;

	int k;
	cin>>k;
	if(k==0){cout<<"1"<<endl;return 0;}

	int n=(int)s.length();
	vector<pair<int,int> > v;
	int y=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){v.push_back(make_pair(i+1,y+1));}
		else{y++;}
	}

	LL total = 0;
	for(int i=0;i<(int)G[k].size();i++){
		int u = G[k][i];
		if(u>n){continue;}
		total = (total + ncr[n][u])%M;
	}
	
	for(int i=0;i<(int)v.size();i++){
		pair<int,int> p = v[i];
		int x = p.first;
		y = p.second;

		for(int j=0;j<(int)G[k].size();j++){
			int u = G[k][j];
			if((u<y) || (n<x) || ((u-y)>(n-x))){continue;}
			total = (total - ncr[n-x][u-y] + M)%M;
		}
	}
	if(k==1){total = (total - 1 + M)%M;}
	cout<<total<<endl;
}