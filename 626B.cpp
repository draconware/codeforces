#include<bits/stdc++.h>
using namespace std;

bool val[209][209][209];
bool a,b,c;

void dp(int i,int j,int k){
	//cout<<i<<" "<<j<<" "<<k<<endl;
	if(i<0 || j<0 || k<0){return ;}
	if(val[i][j][k]){return ;}
	if(i==0 && j==0){
		if(k==0){return ;}
		else{c=true;return ;}
	}
	if(i==0 && k==0){
		if(j==0){return ;}
		else{b=true;return ;}
	}
	if(j==0 && k==0){
		if(i==0){return ;}
		else{a=true;return ;}
	}
	val[i][j][k]=true;
	dp(i-1,j-1,k+1);dp(i-1,j+1,k-1);dp(i+1,j-1,k-1);
	if(i>1){dp(i-1,j,k);}
	if(j>1){dp(i,j-1,k);}
	if(k>1){dp(i,j,k-1);}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	memset(val,0,sizeof(val));

	int n;
	cin>>n;

	string s;
	cin>>s;

	int x=0,y=0,z=0;
	for(int i=0;i<n;i++){
		if(s[i]=='R'){x++;}
		else if(s[i]=='G'){y++;}
		else{z++;}
	}
	a=false;b=false;c=false;
	//cout<<x<<" "<<y<<" "<<z<<endl;
	dp(x,y,z);
	if(c){cout<<"B";}
	if(b){cout<<"G";}
	if(a){cout<<"R";}
//	if(b){cout<<"G";}
//	if(c){cout<<"B";}
	cout<<endl;
}