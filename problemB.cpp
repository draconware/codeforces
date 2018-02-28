#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=10;
	char arr[10][10];
	for(int i=0;i<10;i++){
		cin>>arr[i];
	}
	pair<int,int> res1[10][10],res2[10][10],res3[10][10]res4[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(arr[i][j]=='X'){
				if(j-1>=0){res1[i][j].first = res1[i][j-1].first+1;}
				else{res1[i][j].first=1;}
				res1[i][j].second=0;
			}else if(arr[i][j]=='O'){
				if(j-1>=0){res1[i][j].second = res1[i][j-1].second+1;}
				else{res1[i][j].second=1;}
				res1[i][j].first=0;
			}else{
				if(j-1>=0){res1[i][j].first = res1[i][j-1].first+1;}
				else{res1[i][j].first=1;}
				if(j-1>=0){res1[i][j].second = res1[i][j-1].second+1;}
				else{res1[i][j].second=1;}
			}
		}
	}
	if(query(res1,10)){
		cout<<"YES"<<endl;
		return 0;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(arr[j][i]=='X'){
				if(j-1>=0){res2[j][i].first=res2[j-1][i].first+1;}
				else{res2[j][i].first=1;}
				res2[j][i].second=0;
			}else if(arr[i][j]=='O'){
				if(j-1>=0){res1[j][i].second = res2[j-1][i].second+1;}
				else{res1[j][i].second=1;}
				res1[j][i].first=0;
			}else{
				if(j-1>=0){res1[j][i].first = res2[j-1][i].first+1;}
				else{res1[j][i].first=1;}
				if(j-1>=0){res1[j][i].second = res2[j-1][i].second+1;}
				else{res1[j][i].second=1;}
			}
		}
	}
	if(query(res2,10)){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int j=0;j<10;j++){
		int k=0;
		while(j<10 && k<10){
			if(arr[k][j]=='X'){
				if(j-1>=0 && k-1>=0){res3[k][j].first = res3[k-1][j-1].first +1;}
				else{res3[k][j].first=1;}
				res3[k][j].second=0;
			}else if(arr[k][j]=='O'){
				if(j-1>=0 && k-1>=0){res3[k][j].second = res3[k-1][j-1].second +1;}
				else{res3[k][j].second=1;}
				res3[k][j].first=0;
			}else{
				if(j-1>=0 && k-1>=0){res3[k][j].first = res3[k-1][j-1].first +1;}
				else{res3[k][j].first=1;}
				if(j-1>=0 && k-1>=0){res3[k][j].second = res3[k-1][j-1].second +1;}
				else{res3[k][j].second=1;}
			}
			k++;j++;
		}
	}
	for(int j=1;j<10;j++){
		k=0;
		while(k<10 && j<10){
			if(arr[k][j]=='X'){
				if(j-1>=0 && k-1>=0){res3[j][k].first = res3[j-1][k-1].first +1;}
				else{res3[j][k].first=1;}
				res3[j][k].second=0;
			}else if(arr[j][k]=='O'){
				if(j-1>=0 && k-1>=0){res3[j][k].second = res3[j-1][k-1].second +1;}
				else{res3[j][k].second=1;}
				res3[j][k].first=0;
			}else{
				if(j-1>=0 && k-1>=0){res3[j][k].first = res3[j-1][k-1].first +1;}
				else{res3[j][k].first=1;}
				if(j-1>=0 && k-1>=0){res3[j][k].second = res3[j-1][k-1].second +1;}
				else{res3[j][k].second=1;}
			}
			k++;j++;
		}
	}
	if(query(res3,10)){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
}