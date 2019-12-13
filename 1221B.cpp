#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int n;
char arr[109][109];

bool chk(int x,int y){
	if(x<0 || y<0 || x>=n || y>=n || arr[x][y]!='.'){return false;}
	return true;
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

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j] = '.';
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]=='.'){
				arr[i][j] = 'W';
				char c = 'B';
				if(chk(i+1,j+2)){
					arr[i+1][j+2] = c;
				}
				if(chk(i-1,j+2)){
					arr[i-1][j+2] = c;
				}
				if(chk(i-1,j-2)){
					arr[i-1][j-2] = c;
				}
				if(chk(i+1,j-2)){
					arr[i+1][j-2] = c;
				}
				if(chk(i+2,j-1)){
					arr[i+2][j-1] = c;
				}
				if(chk(i+2,j+1)){
					arr[i+2][j+1] = c;
				}
				if(chk(i-2,j+1)){
					arr[i-2][j+1] = c;
				}
				if(chk(i-2,j-1)){
					arr[i-2][j-1] = c;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}