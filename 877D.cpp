#include<bits/stdc++.h>
using namespace std;

int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};
int n,m;
bool mark[1009][1009];
int level[1009][1009];
char arr[1009][1009];

bool chk(int i,int j){
	if(i>=n || i<0 || j>=m || j<0 || arr[i][j]=='#'){return false;}
	else{return true;}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int k;
	cin>>n>>m>>k;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int fs,fe,ss,se;
	cin>>fs>>fe>>ss>>se;
	fs--;fe--;ss--;se--;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){level[i][j]=INT_MAX;}
	}

	queue<pair<int,int> > q;
	q.push(make_pair(fs,fe));
	memset(mark,0,sizeof(mark));
	mark[fs][fe]=true;
	level[fs][fe]=0;

	while(!q.empty()){
		int u = q.front().first,v = q.front().second;q.pop();
		if(u==ss && v==se){cout<<level[ss][se]<<endl;return 0;}
		//cout<<"for "<<u<<","<<v<<"---- ";
		for(int i=0;i<4;i++){
			for(int j=1;j<=k;j++){
				int nu = u + j*x[i],nv = v + j*y[i];
				if(!chk(nu,nv) || (level[nu][nv]!=INT_MAX && level[nu][nv]<level[u][v]+1)){break;}
				if(!mark[nu][nv] && level[nu][nv] > level[u][v]+1){
					level[nu][nv] = level[u][v]+1;
					q.push(make_pair(nu,nv));
					mark[nu][nv]=true;
				}
			}
		}
		//cout<<endl;
	}
	cout<<"-1"<<endl;
}	