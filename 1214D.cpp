#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int n,m;
vector<string> v;
vector<vector<bool> > mask; 

bool chk(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m || (v[x][y]=='#')){return false;}
	return true;
}

void bfs(){
	bool mark[n][m];
	memset(mark,0,sizeof(mark));

	queue<pair<int,int> > q;
	q.push(mp(0,0));

	while(!q.empty()){
		pii p = q.front();
		q.pop();
		int x = p.ff;
		int y = p.ss;
		//cout<<x<<" "<<y<<endl;
		if(mark[x][y]){continue;}
		mark[x][y] = true;

		if(chk(x+1,y) && !mark[x+1][y]){
			q.push(mp(x+1,y));
		}
		if(chk(x,y+1) && !mark[x][y+1]){
			q.push(mp(x,y+1));
		}
	}
	for(int i=0;i<n;i++){
		vector<bool> tmp;
		for(int j=0;j<m;j++){
			tmp.pb(mark[i][j]);
		}
		mask.pb(tmp);
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

	cin>>n>>m;

	for(int i=0;i<n;i++){
		string s;cin>>s;
		v.pb(s);
	}

	bfs();

	if(!mask[n-1][m-1]){cout<<"0"<<endl;return 0;}
	int ans = 2;

	for(int k=1;k<m;k++){
		int i=0,res=0,j=k;
		while(j>=0 && i<n){
			if(mask[i][j]){res++;}
			j--;
			i++;
		}
		ans = min(ans,res);
	}
	for(int k=1;k<n-1;k++){
		int j=m-1,i=k,res=0;
		while(i<n && j>=0){
			if(mask[i][j]){res++;}
			i++;j--;
		}
		ans = min(ans,res);
	}
	cout<<ans<<endl;
}