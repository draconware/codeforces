#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,maxi,pos;
    cin>>n>>m;

    int arr[n];
    memset(arr,0,sizeof(arr));

    for(int i=0;i<m;i++){
        maxi = INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a > maxi){maxi=a;pos=i;}
        }
        arr[pos]++;
    }
    maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > maxi){maxi=arr[i];pos=i;}
    }
    cout<<pos+1<<endl;
}
