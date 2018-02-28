#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	char arr[n][m];
	bool mark[30];
	memset(mark,0,sizeof(mark));
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n%3 == 0 || m%3 == 0){
		bool flag=true;
		if(n%3 == 0){
			mark[arr[0][0]-'A']=true;
			char c = arr[0][0];
			for(int i=0;i<(n/3);i++){
				for(int j=0;j<m;j++){
					if(arr[i][j] != c){flag=false;break;}
				}
				if(!flag){break;}
			}
			
			if(flag && !mark[arr[n/3][0]-'A']){
				mark[arr[n/3][0]-'A']=true;
				c = arr[n/3][0];
				for(int i=n/3;i<(2*(n/3));i++){
					for(int j=0;j<m;j++){
					if(arr[i][j] != c){flag=false;break;}
					}
					if(!flag){break;}
				}
			}else{
				flag=false;
			}
			
			if(flag && !mark[arr[(2*n)/3][0]-'A']){
				mark[arr[(2*n)/3][0]-'A']=true;
				c = arr[(2*n)/3][0];
				for(int i=(2*(n/3));i<n;i++){
					for(int j=0;j<m;j++){
						if(arr[i][j] != c){flag=false;break;}
					}
					if(!flag){break;}
				}
			}
			if(flag){cout<<"YES"<<endl;return 0;}
		}
		memset(mark,0,sizeof(mark));
		if(m%3 == 0){
			flag=true;
			mark[arr[0][0]-'A']=true;
			char c = arr[0][0];
			for(int i=0;i<(m/3);i++){
				for(int j=0;j<n;j++){
					if(arr[j][i] != c){flag=false;break;}
				}
				if(!flag){break;}
			}
			
			if(flag && !mark[arr[0][m/3]-'A']){
				mark[arr[0][m/3]-'A']=true;
				c = arr[0][m/3];
				for(int i=m/3;i<(2*(m/3));i++){
					for(int j=0;j<n;j++){
					if(arr[j][i] != c){flag=false;break;}
					}
					if(!flag){break;}
				}
			}else{
				flag=false;
			}
			
			if(flag && !mark[arr[0][(2*m)/3]-'A']){
				mark[arr[0][(2*m)/3]-'A']=true;
				c = arr[0][(2*m)/3];
				for(int i=(2*(m/3));i<m;i++){
					for(int j=0;j<n;j++){
						if(arr[j][i] != c){flag=false;break;}
					}
					if(!flag){break;}
				}
			}
			if(flag){cout<<"YES"<<endl;return 0;}
			else{cout<<"NO"<<endl;}
		}
	}else{
		cout<<"NO"<<endl;
	}
}