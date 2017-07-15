#include<bits/stdc++.h>
using namespace std;

#define  LD long double

int main(){
    LD x,y;
    cin>>x>>y;

    LD a,b;
    a = floor(sqrt(x));
    b = sqrt(1.0 + 4.0*y) - 1.0;
    b = floor(b/2.0);

    //cout<<x<<","<<y<<","<<sqrt(1.0 + 4.0*b);
    if(a>b){
        cout<<"Valera"<<endl;
    }else{
        cout<<"Vladik"<<endl;
    }

    return 0;
}
