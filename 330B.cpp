#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n,m;
	cin>>n>>m;

	bool mark[n+9];
	memset(mark,0,sizeof(mark));
	for(int i=0,x,y;i<m;i++){
		cin>>x>>y;
		mark[x]=true;mark[y]=true;
	}
	int s;
	for(int i=1;i<=n;i++){
		if(!mark[i]){s=i;break;}
	}
	cout<<n-1<<endl;
	for(int i=1;i<=n;i++){
		if(i!=s){
			cout<<s<<" "<<i<<endl;
		}
	}
	return 0;
}
