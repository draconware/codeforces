#include<bits/stdc++.h>
using namespace std;

int main(){
    int p,n,t;
    cin>>n>>t;

    vector<int> arr;//v1;
    for(int i=0;i<n;i++){
        cin>>p;
        arr.push_back(p);
    }
    //v1=v;
    while(t--){
        int l,r,z;
        cin>>l>>r>>z;

        if(l == r){
            cout<<"Yes"<<endl;
        }else{
            int x=0,y=0;
            for(int i=l-1;i<z-1;i++){
                //cout<<arr[i]<<","<<arr[z]<<endl;
                if(arr[i] > arr[z-1]){
                    x++;
                  //  cout<<i<<endl;
                }
            }
            //cout<<",,,"<<l<<endl;
            for(int i=r-1;i>z-1;i--){
                //cout<<arr[i]<<arr[z-1]<<endl;
                if(arr[i] < arr[z-1]){
                    y++;
                    //cout<<i<<endl;
                }
            }
           // cout<<",,,"<<r<<endl;
            if(x == y){cout<<"Yes"<<endl;}
            else{cout<<"No"<<endl;}
        }
    }
    arr.clear();
    return 0;
}
