#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL M = (LL)(1e9+7);
int n;
string s;
LL dp[2509][2509];


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>s;

	n = (int)s.length();

	int a = 0,ans = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '('){a++;}
		else{
			if(a>0){a--;}
			else{ans++;a=1;}
		}
	}
	ans += (a/2);

	LL res = 0;
	int cnt[2509];
	memset(cnt,0,sizeof(cnt));

	
}