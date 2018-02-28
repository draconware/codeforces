#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n,m,d,x;
	cin>>n>>m>>d;

	vector<int> v;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			v.push_back(arr[i][j]);
		}
	}
	sort(v.begin(),v.end());
	int size = (int)v.size();
	
	bool flag=false;
	//if(flag){cout<<"-1"<<endl;return 0;}
	int best=INT_MAX;
	if(size%2 == 0){
		int x = v[size/2];
		int y = v[size/2 -1];
		//int best=iNT_MAX;
		//cout<<x<<" "<<y<<endl;
		int sum=0;
		for(int i=0;i<size;i++){
			int t = abs(v[i]-x);
			if(t%d != 0){flag=true;break;}
			sum += (t/d);
		}
		best=min(best,sum);
		sum=0;
		for(int i=0;i<size;i++){
			int t = abs(v[i]-y);
			if(t%d != 0){flag=true;break;}
			sum += (t/d);
		}
		best = min(best,sum);
	}else{
		int x = v[size/2];
		//cout<<x<<endl;
		int sum=0;
		for(int i=0;i<size;i++){
			int t = abs(v[i]-x);
			if(t%d != 0){flag=true;break;}
			sum += (t/d);
		}
		best=min(best,sum);
	}
	if(flag){cout<<"-1"<<endl;}
	else{cout<<best<<endl;}
}