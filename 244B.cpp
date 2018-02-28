#include<bits/stdc++.h>
using namespace std;

#define LL int

int n;
LL ans=0;
bool mark[10];

bool chk(LL num){
	if(num<=0){return false;}
	for(int i=0;i<10;i++){mark[i]=false;}
	while(num>0){
		mark[num%10]=true;
		num/=10;
	}
	int cnt=0;
	for(int i=0;i<10;i++){if(mark[i]){cnt++;}}
	if(cnt<=2){return true;}
	return false;
}

void dfs(int num){
	if(num>0 && num<=n){ans++;}
	if(num>n){return ;}
	for(LL i=0;i<10;i++){
		if(chk(num*10 + i)){
			dfs(num*10 + i);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;

	dfs(0LL);
	cout<<ans<<endl;
}