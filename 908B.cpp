#include<bits/stdc++.h>
using namespace std;

char arr[60][60];
string dir;
int x[4] = {-1,0,0,1};
int y[4] = {0,1,-1,0};
int z[4] = {0,1,2,3};
int ans=0;
bool flag;
pair<int,int> start,stop;
int n,m;

bool chk(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m){return true;}
	return false;
}

void solve(){
	int len = (int)dir.length();
	
	pair<int,int> curr = start;
	for(int i=0;i<len;i++){
		curr.first = curr.first + x[z[dir[i]-'0']];
		curr.second = curr.second + y[z[dir[i]-'0']];
		if(chk(curr.first,curr.second) || arr[curr.first][curr.second]=='#'){
			break;
		}
		if(curr == stop){break;}
	}
	if(curr == stop){ans++;}
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
		cin>>arr[i];
		for(int j=0;j<m;j++){
			if(arr[i][j]=='S'){start = make_pair(i,j);}
			if(arr[i][j]=='E'){stop = make_pair(i,j);}
		}
	}
	cin>>dir;

	solve();
	while(next_permutation(z,z+4)){
		solve();
	}
	cout<<ans<<endl;
}