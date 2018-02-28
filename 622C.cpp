#include<bits/stdc++.h>
using namespace std;

int arr[2*100009];
int pos[2*100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++){cin>>arr[i];}
	pos[0] = -1;

	for(int i=1;i<n;i++){
		if(arr[i] == arr[i-1]){pos[i] = pos[i-1];}
		else{pos[i] = i-1;}
	}

	for(int i=0;i<m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		l--;r--;
		if(arr[r] != x){cout<<r+1<<endl;}
		else{
			if(pos[r]>=l){cout<<pos[r]+1<<endl;}
			else{cout<<"-1"<<endl;}
		}
	}
}