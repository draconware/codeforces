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

	string s;
	cin>>s;

	int n = (int)s.length();

	int x = (n-1)/2;
	bool flag=false;
	for(int i=1;i<n;i++){
		if(s[i]=='1'){flag=true;break;}
	}

	if(!flag && (n%2 == 1)){
		cout<<x<<endl;
	}else{
		cout<<x+1<<endl;
	}
}