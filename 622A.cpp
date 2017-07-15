#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    LL n;
    cin>>n;

    LL x=1;

    while(1){
        LL y = x*(x+1);
        if(y >= (2*n)){
            n-=(((x-1)*x)/2);
            cout<<n<<endl;
            break;
        }else{
            x++;
        }
    }
    return 0;
}
