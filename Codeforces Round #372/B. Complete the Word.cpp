#include<bits/stdc++.h>
using namespace std;

#define LL long long

int freq[30];

int main(){
    memset(freq,0,sizeof(freq));
    string s;
    cin>>s;

    queue<int> q;
    int k=26;
    if(s.length()<26){cout<<"-1"<<endl;return 0;}
    for(int i=0;i<26;i++){
        freq[str[i]-'A']++;
        q.push(i);
    }
    if(!check(freq)){
        cout<<"-1"<<endl;
        return 0;
    }
    while(k<s.length()){
        int p = q.front();

    }

}
