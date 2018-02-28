#include<bits/stdc++.h>
using namespace std;

vector<int> v[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	for(int x,y,i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bool mark[n+9],flag=true;
	memset(mark,0,sizeof(mark));
	int color[n+9];
	memset(color,-1,sizeof(color));

	for(int i=1;i<=n;i++){
		if(!mark[i]){
			//cout<<i<<"---- ";
			queue<int> q;
			q.push(i);
			color[i]=0;
			while(!q.empty()){
				int s = q.front();q.pop();
				mark[s]=true;
				for(int j=0;j<(int)v[s].size();j++){
					if(color[v[s][j]]==-1){color[v[s][j]] = 1-color[s];}
					else{
						if(color[v[s][j]] == color[s]){flag=false;break;}
					}
					if(!mark[v[s][j]]){
						color[v[s][j]]=1-color[s];
						q.push(v[s][j]);
					}
				}
				if(!flag){break;}
			}
			//cout<<endl;
		}
	}
	vector<int> first,second;
	//for(int i=1;i<=n;i++){cout<<color[i]<<" ";}cout<<endl;
	if(!flag){
		cout<<"-1"<<endl;
	}else{
		for(int i=1;i<=n;i++){
			if(color[i]==1){first.push_back(i);}
			else{second.push_back(i);}
		}
		sort(first.begin(),first.end());
		sort(second.begin(),second.end());
		cout<<first.size()<<endl;
		if(first.size()>0){for(int i=0;i<(int)first.size();i++){cout<<first[i]<<" ";}cout<<endl;}

		cout<<second.size()<<endl;
		if(second.size()>0){for(int i=0;i<(int)second.size();i++){cout<<second[i]<<" ";}cout<<endl;}
	}
	return 0;
}