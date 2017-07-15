#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,c,p,ans;
    cin>>n>>t>>c;

    vector<int> v;

    for(int i=0;i<n;i++){
        cin>>p;
        v.push_back(p);
    }

    sort(v.begin(),v.end());

    vector<int>::iterator it;
    it = lower_bound(v.begin(),v.end(),t);

    if(it == v.end()){
        ans = (n-c+1);
    }else{
        int x = it-v.begin();
        ans = (x-c+1);
    }

    if(ans<0){
        cout<<"0"<<endl;
    }else{
        cout<<ans<<endl;
    }

    return 0;
}
