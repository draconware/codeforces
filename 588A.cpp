#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,price=INT_MAX,ans=0,a,b;
    cin>>n;

    while(n--){
        cin>>a>>b;
        price = min(price,b);
        ans+=(price*a);
    }
    cout<<ans<<endl;
}
