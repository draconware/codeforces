#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

char arr[2009][2009];
int l[2009],r[2009];
int val[2009][2009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin>>n>>k;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}

	int fixed=0;

	for(int i=1;i<=n;i++){
		l[i] = n+1;r[i] = 0;
		for(int j=1;j<=n;j++){
			if(arr[i][j]=='B'){
				l[i] = min(l[i],j);
				r[i] = max(r[i],j);
			}
		}
		if(l[i]>r[i]){
			fixed++;
		}
	}



	for(int j=1;j<=n-k+1;j++){
		int i=1,res=0;
		while(i<=k){
			if(l[i]>=j && r[i]<=j+k-1 && l[i]<=r[i]){
				res++;
			}
			i++;
		}
		val[i-k][j] = res;
		while(i<=n){
			if(l[i]>=j && r[i]<=j+k-1 && l[i]<=r[i]){
				res++;
			}
			if(l[i-k]>=j && r[i-k]<=j+k-1 && l[i-k]<=r[i-k]){
				res--;
			}
			i++;
			val[i-k][j] = res;
		}
	}

	for(int j=1;j<=n;j++){
		l[j] = n+1;r[j] = 0;
		for(int i=1;i<=n;i++){
			if(arr[i][j] == 'B'){
				l[j] = min(l[j],i); 
				r[j] = max(r[j],i);
			}
		}
		if(l[j] > r[j]){
			fixed++;
		}
	}

	for(int i=1;i<=n-k+1;i++){
		int j=1,res=0;
		while(j<=k){
			if(l[j]>=i && r[j]<=i+k-1 && l[j]<=r[j]){
				res++;
			}
			j++;
		}
		val[i][j-k] += res;
		while(j<=n){
			if(l[j]>=i && r[j]<=i+k-1 && l[j]<=r[j]){
				res++;
			}
			if(l[j-k]>=i && r[j-k]<=i+k-1 && l[j-k]<=r[j-k]){
				res--;
			}
			j++;
			val[i][j-k] += res;
		}
	}

	int maxi = 0;

	for(int i=1;i<=n-k+1;i++){
		for(int j=1;j<=n-k+1;j++){
			maxi = max(maxi,val[i][j]);
		}
	}
	cout<<maxi+fixed<<endl;
}