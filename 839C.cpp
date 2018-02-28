#include<bits/stdc++.h>
using namespace std;

vector<int> v[100009];
double ans[100009];

double dfs(int s,int p){
	int c=0;
	for(int i=0;i<v[s].size();i++){
		if(v[s][i] != p){
			ans[s]+=dfs(v[s][i]);c++;
		}
	}
	if(c==0){return ans[s];}
	else{ans[s] = ans[s]/(double)c;ans[s]+=1;return ans[s];}
}

int main(){
	int n;
	cin>>n;

	for(int x,y,i=0;i<n-1;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(ans,0,sizeof(ans));
	cout<<dfs(1,0)<<endl;
}