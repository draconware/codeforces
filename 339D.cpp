#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL n,m;

void operation(LL *st,LL i){
    LL x = i+1;
    x = (LL)floor( log2(x) );

    if(n%2){
        if(x%2){
            st[i] = st[2*i+1] ^ st[2*i+2];
        }else{
            st[i] = st[2*i+1] | st[2*i+2];
        }
    }else{
        if(x%2){
            st[i] = st[2*i+1] | st[2*i+2];
        }else{
            st[i] = st[2*i+1] ^ st[2*i+2];
        }
    }
}

void construct(LL arr[],LL *st,LL s,LL e,LL i){
    if(s == e){
        st[i] = arr[s];
    }else{
        LL m = (s+((e-s)/2));

        construct(arr,st,s,m,2*i+1);
        construct(arr,st,m+1,e,2*i+2);

        operation(st,i);
    }
}

void update(LL *st,LL p){
    LL x,k = n;
    while(k--){
        if(p%2){
            x = (p-1)/2;
            operation(st,x);
        }else{
            x = (p-2)/2;
            operation(st,x);
        }
        p = x;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    LL n1 = (LL)pow(2,n);
    LL arr[n1];

    for(LL i=0;i<n1;i++){
        cin>>arr[i];
    }

    LL *st;
    LL max_size = 2*n1 - 1;

    st = (LL*)malloc(max_size*(sizeof(LL)));

    construct(arr,st,0,n1-1,0);

    while(m--){
        LL p,b;
        cin>>p>>b;

        p = n1-2+p;

        st[p] = b;
        update(st,p);

        cout<<st[0]<<endl;
    }

    return 0;
}
