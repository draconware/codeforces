#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a=0,b=0,c=0,x;
    for(int i=0;i<n;i++){
        cin>>x;a+=x;
        cin>>x;b+=x;
        cin>>x;c+=x;
    }
    if(a==0 && b==0 && c==0){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
}
