#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int pre[200009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		string s;cin>>s;
		int n = (int)s.length();

		for(int i=0;i<n;i++){pre[i] = 0;}
		if(s[0]=='0'){pre[0]++;}

		for(int i=1;i<n;i++){
			if(s[i]=='0'){pre[i] = pre[i-1]+1;}
			else{pre[i] = 0;}
		}

		int ans=0;
		for(int i=0;i<n;i++){
			int sum=0;
			for(int j=i;j>=0 && (i-j)<18;j--){
				if(s[j]=='0'){continue;}
				sum+=(1<<(i-j));
				int size = i-j+1;
				if(j>0){size+=(pre[j-1]);}
				if(sum<=size){ans++;}
			}
		}
		cout<<ans<<endl;
	}
}