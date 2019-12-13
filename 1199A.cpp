#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int arr[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,x,y;
	cin>>n>>x>>y;

	for(int i=1;i<=n;i++){cin>>arr[i];}

	for(int i=1;i<=n;i++){
		int cnt=1;
		int j = i-1;
		int mini = arr[i];
		while(cnt<=x && j>0){
			mini = min(mini,arr[j]);
			j--;cnt++;
		}
		cnt=1;j=i+1;
		while(cnt<=y && j<=n){
			mini = min(mini,arr[j]);j++;cnt++;
		}
		if(mini>=arr[i]){cout<<i<<endl;break;}
	}
}