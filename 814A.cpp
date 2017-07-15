#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,l;
    cin>>n>>k;

    vector<int> v1,v2;
    for(int i=0;i<n;i++){
        cin>>l;
        v1.push_back(l);
    }
    for(int i=0;i<k;i++){
        cin>>l;
        v2.push_back(l);
    }
    sort(v2.begin(),v2.end());
    int c=k-1;
    for(int i=0;i<n;i++){
        if(v1[i] == 0){
            v1[i]=v2[c];
            c--;
        }
    }
    for(int i=0;i<n-1;i++){
        if(v1[i+1]<v1[i]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
