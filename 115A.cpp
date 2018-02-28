#include<bits/stdc++.h>
using namespace std;

vector<int> v[2009];

int main(){
	int n;
	cin>>n;

	bool mark[n+9];
	memset(mark,0,sizeof(mark));
	vector<int> eval;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(x==-1){eval.push_back(i);}
		else{
			v[x].push_back(i);
		}
	}
	int best=INT_MAX;
	for(int i=0;i<(int)eval.size();i++){
		if(!mark[eval[i]]){
			int s=eval[i];
			queue<pair<int,int> > q;
			q.push(make_pair(s,0));

			int y=0;
			while(!q.empty()){
				pair<int,int> p = q.front();q.pop();
				int x = p.first,w = p.second;
				mark[x]=true;
				y=w;
				for(int j=0;j<v[x].size();j++){
					if(!mark[v[x][i]]){
						q.push(make_pair(v[x][i],w+1));
					}
				}
			}
			best=min(best,y);
		} 
	}
	cout<<best<<endl;
}