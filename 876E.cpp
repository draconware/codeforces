#include<bits/stdc++.h>
using namespace std;

vector<int> G[100009];
bool capital[100009];
bool mark[100009];

void dfs(int s){
	mark[s]=true;
	if(capital[s]){
		for(int i=0;i<G[s].size();i++){
			capital[G[s][i]]=true;
		}
	}
	for(int i=0;i<G[s].size();i++){
		if(!mark[G[s][i]]){dfs(G[s][i]);}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	vector<vector<int> > v;
	for(int i=0;i<n;i++){
		int len;cin>>len;
		vector<int> temp(len);	
		for(int j=0,x;j<len;j++){
			cin>>temp[j];
		}
		v.push_back(temp);
	}
	memset(capital,0,sizeof(capital));
	for(int i=0;i<n-1;i++){
		vector<int> fir = v[i];
		vector<int> snd = v[i+1];

		for(int j=0;j<min(fir.size(),snd.size());j++){
			if(fir[j] > snd[j]){capital[fir[j]]=true;break;}
			else if(fir[j] < snd[j]){G[snd[j]].push_back(fir[j]);break;}
		}
	}
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=m;i++){
		if(capital[i]){dfs(i);}
	}
	bool flag=true;
	for(int i=0;i<n-1;i++){
		vector<int> fir = v[i];
		vector<int> snd = v[i+1];
		int x=0;

		for(int j=0;j<min(snd.size(),fir.size());j++){
			if(fir[j]>snd[j]){x++;
				if(!(capital[fir[j]] && !capital[snd[j]])){flag=false;}break;
			}else if(fir[j]==snd[j]){
				if(!capital[fir[j]] && capital[snd[j]]){flag=false;break;}
			}else{x++;
				if(!capital[fir[j]] && capital[fir[j]]){flag=false;}break;
			}
		}
		if(!flag){break;}
		if(fir.size()>snd.size() && x==0){flag=false;break;}
	}
	if(flag){
		cout<<"Yes"<<endl;
		int ans=0;
		for(int i=1;i<=m;i++){if(capital[i]){ans++;}}
		cout<<ans<<endl;
		for(int i=1;i<=m;i++){if(capital[i]){cout<<i<<" ";}}
		if(ans>0){cout<<endl;}
	}else{
		cout<<"No"<<endl;
	}
}