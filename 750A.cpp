#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	int x = 240-m;
	int i=1,ans=0;
	while(x>=5*i && i<=n){
		ans++;x-=5*i;
		i++;
	}
	cout<<ans<<endl;
}