#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,h,i,ans =0;
        cin>>n>>h;

        int ara[n+2];
        for(i=0; i<n; i++)cin>>ara[i];
        int x=0,d=h;
        sort(ara,ara+n);

        for(i=n-1;i>=0;i--)
        {
            x = x + ara[i];
            if(x >= h)
                break;
        }

        if(i==-1)cout<<0<<endl;
        else cout<<ara[i]<<endl;
    }
    return 0;
}
