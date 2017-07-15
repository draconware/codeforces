#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,a,x,ans1,ans2;

    cin>>n>>m>>a;

    x = n;
    n = max(n,m);
    m = min(x,m);

    ans1 = (n/a);
    if(n%a){
        ans1++;
    }

    ans2 = (m/a);
    if(m%a){
        ans2++;
    }

    cout<<ans1*ans2<<endl;
}
