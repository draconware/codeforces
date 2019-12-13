#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
	
int data[200009][30];
int curr[30];

void pre(string s){
	int n = (int)s.length();
	data[0][s[0]-'a']++;
	for(int i=1;i<n;i++){
		int x = s[i]-'a';
		for(int j=0;j<26;j++){
			data[i][j] = data[i-1][j];
		}
		data[i][x]++;
	}
}

bool f(int idx){
	for(int i=0;i<26;i++){
		if(data[idx][i]<curr[i]){return false;}
	}
	return true;
}

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

	string s;cin>>s;

	pre(s);

	int m;
	cin>>m;

	for(int i=0;i<m;i++){
		string s;cin>>s;
		memset(curr,0,sizeof(curr));
		for(int j=0;j<(int)s.length();j++){
			curr[s[j]-'a']++;
		}
		int l=0,r=n-1,ans=n-1;
		while(l<=r){
			int m = (l+r)/2;
			if(f(m)){
				ans = m;
				r=m-1;
			}else{
				l=m+1;
			}
		}
		cout<<ans+1<<endl;
	}
}