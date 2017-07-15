#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n;
    int arr[n];
    arr[0]=0;
    for(int i=1;i<n;i++){
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    cin>>a>>b;
    cout<<arr[b-1]-arr[a-1]<<endl;
}
