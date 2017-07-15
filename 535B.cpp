#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>n;

    int len=0;
    m=n;
    while(m){
        len++;
        m/=10;
    }
    //cout<<len<<endl;
    int flag=1,ans = (int)pow(2.0,len) - 2;
    for(int i=0,c=n;i<len;i++){
        m = c%10;
        if(m == 7){
            ans+=(flag*((int)pow(2.0,i)));
        }
        c/=10;
    }
    ans++;
    cout<<ans<<endl;
}

