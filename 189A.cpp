#include<bits/stdc++.h>
using namespace std;

int n,a,b,c,x,y;
int val[4009];

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif
  	int temp[3];
	cin>>n>>temp[0]>>temp[1]>>temp[2];
	x=a;y=b;
	sort(temp,temp+3);
	a=temp[0];b=temp[1];c=temp[2];
	cout<<a<<" "<<b<<" "<<c<<endl;
	memset(val,0,sizeof(val));
	val[0]=1;
	for(int i=a;i<=n;i++){
		if(i>=c){
			val[i] = max(val[i-a]+val[a],max(val[i-b]+val[b],val[i-c]+val[c]));
		}else if(i>=b){
			val[i] = max(val[i-b]+val[b],val[i-a]+val[a]);
		}else{
			val[i] = val[a]+val[i-a];
		}
	}
	cout<<val[n]<<endl;
	return 0;
}