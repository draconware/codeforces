#include<bits/stdc++.h>
using namespace std;

vector<int> v[100009];
int res[100009],arr[100009];
bool mark[100009];

int main(){
	int t;
	cin>>t;

	while(t--){
		int x,y,n,m;
		cin>>n>>m;

		for(int i=0;i<m;i++){
			cin>>x>>y;
			v[x].push_back(y);
		}
		for(int i=0;i<=n;i++){
			sort(v[i].begin(),v[i].end());
		}
		memset(arr,0,sizeof(arr));
		memset(mark,0,sizeof(mark));
		int tot=0;
		bool flag=true;
		int c=1;
		memset(res,0,sizeof(res));

		for(int i=0;i<=n;i++){
			c=1;
			for(int j=0;j<v[i].size();j++){
				if(res[v[i][j]]==0){
					res[v[i][j]] = c++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			arr[res[i]]++;
			if(!mark[res[i]]){tot++;mark[res[i]]=true;}
		}
		if(arr[0]>0){flag=false;}
		for(int i=0 ;i<=n;i++){
			if(tot!=v[i].size()){flag=false;break;}
			arr[res[i+]]
		}
	}
}