#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	int num = n*n;
	vector<int> v[n];

	int d=0;

	while(num>0){
		int m = n;
		if(d==0){
			for(int i=0;i<n;i++){
				v[i].push_back(num);
				num--;
			}
		}else{
			for(int i=n-1;i>=0;i--){
				v[i].pb(num);
				num--;
			}
		}
		d = 1-d;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}