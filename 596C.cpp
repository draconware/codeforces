#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i{a};i<b;i++)
#define FORD(i,b,a) for(int i{b};i>=a;i--)
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;
typedef vector<int>VI;
typedef pair<int,int>PII;
typedef vector<LL> VLL;
typedef vector<PII> VPP;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
typedef map<int,int> MAP;
#define ub upper_bound
#define ULL unsigned long long
#define lb lower_bound
#define ceil(x,p) ((x)%(p)?(x)/(p)+1:(x)/(p))
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define abs(a) ((a)>0?(a):-(a))
#define MOD ((int)1e9+7)
#define sz size()
#define T third
#define Md(a) ((a)>=0?(a)%MOD:MOD-(-(a))%MOD)
#define MAXM 100005
struct Trp
{
    int first,second,third;
};
bool comF(Trp a, Trp b)
{
    return a.F==b.F?a.S<b.S:a.F<b.F;
}
bool comS(Trp a,Trp b)
{
    return a.S==b.S?a.F<b.F:a.S<b.S;
}
bool comT(Trp a,Trp b)
{
    return a.T<b.T;
}
int main()
{
    int n;
    cin>>n;
    vector<Trp> a(n);
    FOR(i,0,n)
        scanf("%d%d",&a[i].F,&a[i].S);
    map<int,set<int> > tab;
    FOR(i,1,n+1)
    {
        int w;
        scanf("%d",&w);
        tab[w].insert(i);
    }
    sort(a.begin(),a.end(),comF);
    FOR(i,0,n)
    {
        int w=a[i].S-a[i].F;
        if(tab[w].empty())
        {
            cout<<"NO";
            return 0;
        }
        a[i].T=*tab[w].begin();
        tab[w].erase(tab[w].begin());
    }
   // for(auto x: a)
     //   cout<<x.F<<" "<<x.S<<" "<<x.T<<endl;
    int ix=-1;
    int mm=-1;
    FOR(i,0,n)
    {
       if(a[i].F>ix)
       {
           ix=a[i].F;
           mm=a[i].T;
       }
       else
       {
           if(mm>a[i].T)
           {
               cout<<"NO"<<endl;
               //cout<<i<<" "<<a[i].F<<" "<<a[i].S<<" "<<a[i].T<<" "<<mm<<" "<<a[i].T<<endl;
               return 0;
           }
           else
            mm=a[i].T;
       }
    }
    sort(a.begin(),a.end(),comS);
    //cout<<"boom"<<endl;
    //new
    ix=-1;
    mm=-1;
    FOR(i,0,n)
    {
       if(a[i].S>ix)
       {
           ix=a[i].S;
           mm=a[i].T;
       }
       else
       {
           if(mm>a[i].T)
           {
               cout<<"NO";
               return 0;
           }
           else
            mm=a[i].T;
       }
    }
    cout<<"YES"<<endl;
    sort(a.begin(),a.end(),comT);
    FOR(i,0,n)
        printf("%d %d\n",a[i].F,a[i].S);
}