#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,h,ans=0,i=1;
    cin>>n;

    vector<int> v;
    for(int i=0;i<n;i++){cin>>h;v.push_back(h);}
    ans+=v[0];ans++;
    while(i<n){
        ans++;
        //cout<<ans<<endl;
        ans+=abs(v[i]-v[i-1]);
        ans++;i++;
    }
    cout<<ans<<endl;
}
