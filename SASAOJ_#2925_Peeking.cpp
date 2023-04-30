#include<bits/stdc++.h>
using namespace std;

int v[2000001];

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;
        v[i]=(x=='X');
    }

    int ans=1;
    int cur=k;
    int prev=0;

    while(cur<n+k)
    {
        if(cur==prev) {cout<<-1; return 0;}

        if(v[cur])
        {
            ans++;
            prev=cur;
            cur+=2*k-1;
        }
        else cur--;
    }

    cout<<ans;
}
