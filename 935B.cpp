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

	int n;
	cin>>n;

	int x = 0,y = 0,c;
	string s;
	cin>>s;

	if(s[0] == 'U'){
		y++;c=1;
	}else{
		x++;c=0;
	}

	int ans = 0;
	for(int i=1;i<n;i++){
		int nx = x;
		int ny = y;
		if(s[i] == 'U'){ny++;}
		else{nx++;}

		if(nx > ny){
			if(c==1){ans++;c=0;}
		}else if(nx < ny){
			if(c==0){ans++;c=1;}
		}
		x = nx;y = ny;
	}
	cout<<ans<<endl;
}