#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int arr[1009][1009];

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
	int fill=0;

	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			arr[i][j] = 4*fill + 1;
			arr[i][j+n/2] = 4*fill + 2;
			arr[i+n/2][j] = 4*fill + 3;
			arr[i+n/2][j+n/2] = 4*fill;
			fill++;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}