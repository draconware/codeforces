#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int l=1,h=1000000;

	while(l!=h){
		int m = (l+h+1)/2;
		printf("%d\n",m);
		fflush(stdout);

		string s;
		cin>>s;
		if(s==">="){l=m;}
		else{h=m-1;}
	}
	printf("! %d",l);
}