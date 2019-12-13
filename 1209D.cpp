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

	string s;
	cin>>s;

	int s1=0,s2=0;
	int x=0,y=0;

	for(int i=0;i<n/2;i++){
		if(s[i]=='?'){x++;}
		else{s1+=(s[i]-'0');}
	}
	for(int i=n/2;i<n;i++){
		if(s[i]=='?'){y++;}
		else{s2+=(s[i]-'0');}
	}

	if(s1<=s2){
		swap(s1,s2);
		swap(x,y);
	}
	if(s1==s2){
		if(x!=y){cout<<"Monocarp"<<endl;}
		else{cout<<"Bicarp"<<endl;}
		return 0;
	}

	int diff = s1-s2;
	int val = diff/9;
	if(diff%9 != 0){val++;}

	val*=2;
	if((y-x)==val){cout<<"Bicarp"<<endl;}
	else{cout<<"Monocarp"<<endl;}
}