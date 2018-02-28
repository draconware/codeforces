#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n;
	cin>>n;
	//cout<<"executed"<<endl;
	int arr[n],s[n-1];
	for(int i=0;i<n;i++){cin>>arr[i];}
	for(int i=1;i<n;i++){s[i-1]=arr[i]-arr[i-1];}
	int best=1;
	//j=0,idx=-1,flag=0;
	//for(int i=0;i<n-1;i++){cout<<s[i]<<" ";}cout<<endl;
	int j=0,i=0,idx1=-1,idx2=-1,flag=0;
	while(1){
		while(j<n-1){
			if(s[j]==1){
				if(flag==1){break;}
				flag=1;idx1=j+1;
			}
			if(s[j]>1){
				idx1=j;break;
				flag=2;
			}
			if(s[j]==-1){
				if(flag==-1){break;}
				flag=-1;idx2=j+1;
			}
			if(s[j]<-1){
				flag=-2;idx2=j;break;
			}
			j++;
			//cout<<flag<<endl;
		}
		//cout<<i<<" "<<j<<" "<<flag<<endl;
		best = max(best,j-i+1);
		if(j>=n-2){break;}
		else{
			if(flag==1 || flag==2){i=idx1;idx1=j+1;}
			if(flag==-1 || flag==-2){i=idx2;idx2=j+1;}
		}
		j++;
	}
	cout<<best<<endl;
}