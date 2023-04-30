#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>

ll n,m,c,ans;
vector<pii> v;
vector<ll> lis;

bool safe(int x,int y)
{
    return 0<=x&&x<=n&&0<=y&&y<=m;
}

int main()
{
    cin>>n>>m>>c;

    for(int x,y,i=0;i<c;i++)
    {
        cin>>x>>y;

        if(safe(x,y)) v.push_back({x,y});
    }

    sort(v.begin(),v.end());

    c=v.size();

    lis.push_back(-1);
    for(int i=0;i<c;i++)
    {
        if(lis[ans]<=v[i].second)
        {
            lis.push_back(v[i].second);
            ans++;
            continue;
        }

        ll tmp=upper_bound(lis.begin(),lis.end(),v[i].second)-lis.begin();
        lis[tmp]=v[i].second;
    }

    cout<<ans;
}
