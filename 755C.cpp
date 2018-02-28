#include<bits/stdc++.h>
using namespace std;

int p[10009];
int mark[10009];

int root(int x){
	while(x!=p[x]){
		x=p[x];
	}
	return x;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[n+1];
	for(int i=1;i<=n;i++){
		p[i]=i;
		cin>>arr[i];
	}
	memset(mark,0,sizeof(mark));

	for(int i=1;i<=n;i++){
		int u = root(arr[i]);
		int v = root(i);
		if(u != v){
			p[max(u,v)]=min(u,v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x = root(i);
		if(!mark[x]){ans++;mark[x]=true;}
	}
	cout<<ans<<endl;
}