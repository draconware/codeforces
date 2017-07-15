#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define SQRE(x) (x)*(x)

int main(){
    LL n,k=2,c=1,t,m=2;
    cin>>n;
    cout<<"2"<<endl;
    while(k != n+1){
        t = m*(m+1)*(m+1)-(m-1);
        k++;m++;
        cout<<t<<endl;
    }
    return 0;
}
