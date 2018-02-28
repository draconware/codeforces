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

	int mark[3][11];
	memset(mark,0,sizeof(mark));
	for(int i=0;i<n;i++){
		for(int j=0;j<6;j++){
			int a;cin>>a;
			mark[i][a]++;
		}
	}

	if(n==1){
		for(int i=1;i<10;i++){
			if(mark[0][i]==0){cout<<i-1<<endl;return 0;}
		}
		cout<<"9"<<endl;return 0;
	}else if(n==2){
		for(int i=1;i<10;i++){
			if(mark[0][i]>0 || mark[1][i]>0){
				continue;
			}
			cout<<i-1<<endl;return 0;
		}
		for(int i=10;i<100;i++){
			int x = i;
			if((mark[0][x%10]>0 && mark[1][x/10]>0) || (mark[1][x%10]>0 && mark[0][x/10]>0)){
				continue;
			}
			cout<<i-1<<endl;return 0;
		}
		cout<<"99"<<endl;return 0;
	}else{
		for(int i=1;i<10;i++){
			if(mark[0][i]>0 || mark[1][i]>0 || mark[2][i]>0){
				continue;
			}
			cout<<i-1<<endl;return 0;
		}
		for(int i=10;i<100;i++){
			int x = i;
			if((mark[0][x%10]>0 && mark[1][x/10]>0) || (mark[1][x%10]>0 && mark[0][x/10]>0) || (mark[0][x%10]>0 && mark[2][x/10]>0)
			 || (mark[2][x%10]>0 && mark[0][x/10]>0) || (mark[1][x%10]>0 && mark[2][x/10]>0) || (mark[2][x%10]>0 && mark[1][x/10]>0)){
				continue;
			}
			cout<<i-1<<endl;return 0;
		}
		for(int i=100;i<=999;i++){
			int x = i;
			int x1=x%10,x2 = (x/10)%10,x3 = x/100;
			if((mark[0][x1]>0 && mark[1][x2]>0 && mark[2][x3]>0)||(mark[0][x1]>0 && mark[1][x3]>0 && mark[2][x2]>0)
				|| (mark[0][x2]>0 && mark[1][x1]>0 && mark[2][x3]>0)||(mark[0][x2]>0 && mark[1][x3]>0 && mark[2][x1]>0)
				|| (mark[0][x3]>0 && mark[1][x1]>0 && mark[2][x2]>0) || (mark[0][x3]>0 && mark[1][x2]>0 && mark[2][x1]>0)){continue;}
			cout<<i-1<<endl;return 0;
		}
		cout<<"999"<<endl;
	}
}