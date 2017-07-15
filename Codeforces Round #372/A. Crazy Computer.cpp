#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,c,a;
    cin>>n>>c;

    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }

    int ans=1;
    for(int i=1;i<n;i++){
        if(v[i]-v[i-1] > c){ans=1;}
        else{ans++;}
    }
    cout<<ans<<endl;
}
