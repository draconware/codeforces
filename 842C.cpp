#include<bits/stdc++.h>
using namespace std;

vector<int> profit;
vector<int> edges[200009];
vector<int> ans;
vector<int> divisor,chk;
vector<bool> mark;

int gcd(int a,int b){
	while(a>0){
		int t = a;
		a = b%a;
		b = t;
	}
	return b;
}

void dfs1(int u){
	mark[u]=true;
	for(int i=0;i<edges[u].size();i++){
		if(!mark[edges[u][i]]){
			ans[edges[u][i]] = gcd(ans[u],profit[edges[u][i]]);
			dfs1(edges[u][i]);
		}
	}
}

void dfs2(int s,int dist){
	mark[s]=true;
	for(int i=0;i<divisor.size();i++){
		if((profit[s]%divisor[i])==0){chk[i]++;}
		if(chk[i]>=dist){
			ans[s] = max(ans[s],divisor[i]);
		}
	}
	for(int i=0;i<edges[s].size();i++){
		if(!mark[edges[s][i]]){
			dfs2(edges[s][i],dist+1);
		}
	}
	for(int i=0;i<divisor.size();i++){
		if((profit[s]%divisor[i])==0){chk[i]--;}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	profit.resize(n+1);
	ans.resize(n+1);
	mark.resize(n+1);
	for(int i=1;i<=n;i++){cin>>profit[i];}

	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int x = profit[1];
	profit[1]=0;
	ans[1]=0;
	for(int i=1;i<=n;i++){mark[i]=0;}
	dfs1(1);
	//for(int i=1;i<=n;i++){cout<<ans[i]<<" ";}cout<<endl;
	for(int i=1;i<=n;i++){mark[i]=0;}
	profit[1]=x;
	//for(int i=1;i<=n;i++){cout<<profit[i]<<" ";}cout<<endl;
	for(int i=1;i*i<=x;i++){
		if(x%i == 0){
			divisor.push_back(i);
			divisor.push_back(x/i);
			if(i == x/i){divisor.pop_back();}
		}
	}
	sort(divisor.begin(),divisor.end());
	chk.resize(divisor.size());
	for(int i=0;i<chk.size();i++){chk[i]=0;}
	//for(int i=0;i<divisor.size();i++){cout<<divisor[i]<<" ";}cout<<endl;
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}cout<<endl;
}