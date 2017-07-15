#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}

    bool flag=true,flag2=false;
    bool mark[3];
    int x=0;
    memset(mark,0,sizeof(mark));
    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1]){
            if(mark[0] && x!=0){flag=false;break;}
            mark[0]=true;x=0;
        }
        if(arr[i] == arr[i-1]){
            if(mark[1] && x!=1){flag=false;break;}
            mark[0]=true;
            mark[1]=true;x=1;
        }
        if(arr[i] < arr[i-1]){
            if(mark[2] && x!=2){flag=false;break;}
            mark[0]=true;
            mark[1]=true;
            mark[2]=true;x=2;
        }
    }
    if(flag){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
}
