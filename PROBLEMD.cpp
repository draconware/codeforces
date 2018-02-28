#include<bits/stdc++.h>
using namespace std;

int n;
int val[109][109];
vector<pair<int,int> > v;

pair<int,int> process(long long c){
	int x=0,y=0;
	while(c>0 && c%5 == 0){
		x++;
		c/=5;
	}
	while(c>0 && c%2 == 0){
		y++;
		c/=2;
	}
	return make_pair(y,x);
} 

int dp(int i,int k){
	cout<<i<<","<<k<<endl;
	if(k<0){return 0;}
	if(n-i < k){return 0;}
	if(val[i][k] != -1){return val[i][k];}

	val[i][k] = max(min(v[i].first,v[i].second)+dp(i+1,k-1),dp(i+1,k));
	return val[i][k];
}

int main(){
	int k;
	long long x;
	cin>>n>>k;

	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(process(x));
	}
	memset(val,-1,sizeof(val));
	int ans = dp(0,k);
	cout<<ans<<endl;
}