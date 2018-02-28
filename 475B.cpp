#include<bits/stdc++.h>
using namespace std;

pair<char,char> arr[25][25];
pair<char,char> rarr[25][25];
bool mark[25][25];
int n,m;

void dfs1(int s,int e){
	if(s>=n || s<0 || e>=m || e<0){return ;}
	if(mark[s][e]){return ;}
	mark[s][e]=true;

	if(arr[s][e].first == '>'){dfs1(s,e+1);}
	else{dfs1(s,e-1);}
	if(arr[s][e].second == 'v'){dfs1(s+1,e);}
	else{dfs1(s-1,e);}
}

void dfs2(int s,int e){
	if(s>=n || s<0 || e>=m || e<0){return ;}
	if(mark[s][e]){return ;}
	mark[s][e]=true;

	if(rarr[s][e].first == '>'){dfs2(s,e+1);}
	else{dfs2(s,e-1);}
	if(rarr[s][e].second == 'v'){dfs2(s+1,e);}
	else{dfs2(s-1,e);}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>n>>m;

	char c;
	for(int i=0;i<n;i++){
		cin>>c;
		for(int j=0;j<m;j++){
			arr[i][j].first = c;
			if(c=='>'){rarr[i][j].first = '<';}
			else{rarr[i][j].first = '>';}
		}
	}
	for(int i=0;i<m;i++){
		cin>>c;
		for(int j=0;j<n;j++){
			arr[j][i].second = c;
			if(c=='^'){rarr[j][i].second = 'v';}
			else{rarr[j][i].second = '^';}
		}
	}
	memset(mark,0,sizeof(mark));
	dfs1(0,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!mark[i][j]){cout<<"NO"<<endl;return 0;}
		}
	}
	memset(mark,0,sizeof(mark));
	dfs2(0,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!mark[i][j]){cout<<"NO"<<endl;return 0;}
		}
	}
	cout<<"YES"<<endl;
}