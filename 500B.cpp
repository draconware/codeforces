#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int> 
#define ff first
#define ss second 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;

	int v[n+1];
	int idx[n+1];
	for(int i=1;i<=n;i++){cin>>v[i];idx[v[i]]=i;}	
	char arr[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=1;i<=n;i++){
		int j=1;
		while(idx[i]!=i && j<=n){
			//cout<<v[idx[i]]<<" "<<idx[i]<<" "<<j<<endl;
			if(arr[idx[i]][j]=='1' && v[j]>i){
				//cout<<"executed"<<endl;
				v[idx[i]]=v[j];
				v[j]=i;
				idx[i]=j;
				j=1;
			}else{
				j++;
			}
		}
	}
	for(int i=1;i<=n;i++){cout<<v[i]<<" ";}cout<<endl;
}