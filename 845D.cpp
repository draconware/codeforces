#include <bits/stdc++.h>
using namespace std;
int n,x,s,snow;
int main()
{
    while(cin>>n)
    {
        int tot=0;
        stack<int>q,w;
        q.push(300);
        w.push(1);
        while(n--)
        {
            scanf("%d",&x);
            if(x==1||x==3)scanf("%d",&s);
            switch(x)
            {
                case 1:snow=s;while(!q.empty()&&q.top()<snow){tot++;q.pop();} break;
                case 2:while(!w.empty()&&w.top()<1){tot++;w.pop();}break;
                case 3:if(snow>s)tot++;else q.push(s);break;
                case 4:w.push(1);break;
                case 5:q.push(300);break;
                case 6:w.push(0);break;
                default : ;

            }
        }

        cout<<tot<<endl;

    }

	return 0;
}