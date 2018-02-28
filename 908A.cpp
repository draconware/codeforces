#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin>>s;

	int ans=0;
	int n = (int)s.length();
	int charac[30];
	int num[10];
	memset(charac,0,sizeof(charac));
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++){
		if(s[i]>='a' && s[i]<='z'){charac[s[i]-'a']++;}
		else{num[s[i]-'0']++;}
	}
	ans = charac[0] + charac['e'-'a'] + charac['i'-'a'] + charac['o' - 'a'] + charac['u' - 'a'];
	for(int i=1;i<10;i+=2){
		ans += num[i];
	}
	cout<<ans<<endl;
}