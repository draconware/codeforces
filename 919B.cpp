#include<bits/stdc++.h>
using namespace std;

bool chk(int x){
	int res=0;
	while(x>0){
		res += x%10;
		x/=10;
	}
	if(res == 10){return true;}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin>>k;

	int ans = 19;
	while(k>0){
		if(chk(ans)){k--;}
		ans++;
	}
	cout<<ans-1<<endl;
}