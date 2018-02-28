#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,q,m;
	cin>>n>>q>>m;

	int arr[n+1];
	for(int i=1;i<=n;i++){cin>>arr[i];}

	vector<pair<int,pair<int,int> > > v;
	for(int i=0;i<q;i++){
		int x,y,z;cin>>x>>y>>z;
		v.push_back(make_pair(x,make_pair(y,z)));
	} 
	//cout<<"executed"<<endl;
	//cout<<"executed"<<endl;
	while(m--){
		int x,x1;cin>>x;x1=x;
		//cout<<"executed"<<endl;
		for(int i=q-1;i>=0;i--){
			int t=v[i].first,l=v[i].second.first,r=v[i].second.second;

			if(l<=x && r>=x){
				if(t==1){
					x--;
					if(x<l){x=r;}
				}else{
					x = l+r-x;
				}
			}
		}
		//mark[x1]=arr[x];
		cout<<arr[x]<<" ";
	}
	cout<<endl;
}