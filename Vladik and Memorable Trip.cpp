#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int n;
    cin>>n;
    while(1){
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<n;i++){
        arr[i] = (arr[i]^arr[i-1]);
    }
    cout<<arr[n-1]<<endl;
}}
