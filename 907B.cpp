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

	char arr[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>arr[i][j];
		}
	}

	int x,y;
	cin>>x>>y;

	x--;y--;
	while(x>=3){x-=3;}
	while(y>=3){y-=3;}

	int r1=x*3,r2=x*3+2;
	int c1=y*3,c2=y*3+2;

	bool flag=false;
	for(int i=r1;i<=r2;i++){
		for(int j=c1;j<=c2;j++){
			if(arr[i][j]=='.'){flag=true;arr[i][j]='!';}
		}
	}
	if(flag){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(j==3 || j==6){cout<<" ";}
				cout<<arr[i][j];
			}
			cout<<endl;
			if(i==2 || i==5){cout<<endl;}
		}
	}else{
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(j==3 || j==6){cout<<" ";}
				if(arr[i][j]=='.'){cout<<"!";}
				else{cout<<arr[i][j];}
			}
			cout<<endl;
			if(i==2 || i==5){cout<<endl;}
		}
	}
}